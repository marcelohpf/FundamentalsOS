#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/select.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include "timestamp.h"
#include "io.h"
#define MAX_BUFFER 500
#define READ 0
#define WRITE 1
#define TIME_EXECUTION 30

int main(){
    int lazy_fd[2] = { -1, -1};
    int active_fd[2] = {-1, -1};
    char buffer[MAX_BUFFER];

    if(pipe(lazy_fd) == -1 || pipe(active_fd) == -1){
        perror("pipe initialization error");
        exit(EXIT_FAILURE);
    }

    pid_t pid_one;
    struct timespec start = timestamp();
    pid_one = fork();
    if(pid_one == -1){
        perror("fork call error");
        exit(EXIT_FAILURE);
    } else if(pid_one == 0){
        //printf("child 1: %d\n",pid_one);
        close(lazy_fd[READ]);
        int i=0;
        while(++i){
          lazy_pipe(lazy_fd[WRITE], buffer, sizeof(buffer), i, start);
        }
        close(lazy_fd[WRITE]);
        printf("exited 1\n");
        exit(EXIT_SUCCESS);
    } else {
        pid_t pid_two;
        pid_two = fork();
        if(pid_two == -1){
            perror("fork call error");
            exit(EXIT_FAILURE);
        } else if(pid_two == 0){
            //printf("child 2: %d\n",pid_one);
            close(active_fd[READ]);
            int i=0;
            while(++i){
              active_pipe(active_fd[WRITE], buffer, sizeof(buffer), i, start);
            }
            close(active_fd[WRITE]);
            printf("exited 2\n");
            exit(EXIT_SUCCESS);
        } else {
            fd_set read_set;
            struct timeval tv;
            tv.tv_sec = 2;
            tv.tv_usec = 0;
            close(active_fd[WRITE]);
            close(lazy_fd[WRITE]);
            clean_file();
            struct timespec end;
            do {
              FD_ZERO(&read_set);
              FD_SET(lazy_fd[READ], &read_set);
              FD_SET(active_fd[READ], &read_set);
              int retval = select(active_fd[READ]+1, &read_set, NULL, NULL, &tv);
              if(retval == -1){
                perror("select fail");
                exit(EXIT_FAILURE);
              } else if(retval){
                if(FD_ISSET(active_fd[READ], &read_set)){
                  int readed = read(active_fd[READ], &buffer, sizeof(buffer));
                  write_loaded_pipe(readed, buffer, start);
                } else if (FD_ISSET(lazy_fd[READ], &read_set)){
                  int readed = read(lazy_fd[READ], &buffer, sizeof(buffer));
                  write_loaded_pipe(readed, buffer, start);
                } else {
                  perror("no identified fd in select\n");
                }
              }
              end = timestamp();
            } while((end.tv_sec - start.tv_sec) < TIME_EXECUTION);
            close(active_fd[READ]);
            close(lazy_fd[READ]);
            printf("\nExiting...\n");
            kill(pid_one, SIGTERM);
            kill(pid_two, SIGTERM);
            wait(NULL);
            exit(EXIT_SUCCESS);
        }

    }
    return 0;
}
