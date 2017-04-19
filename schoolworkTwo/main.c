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
        close(lazy_fd[0]);
        int i=0;
        while(++i){
          lazy_pipe(lazy_fd[1], buffer, sizeof(buffer), i, start);
        }
        close(lazy_fd[1]);
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
            close(active_fd[0]);
            int i=0;
            while(++i){
              active_pipe(active_fd[1], buffer, sizeof(buffer), i, start);
            }
            close(active_fd[1]);
            printf("exited 2\n");
            exit(EXIT_SUCCESS);
        } else {
            fd_set read_set;
            struct timeval tv;
            tv.tv_sec = 2;
            tv.tv_usec = 0;
            close(active_fd[1]);
            close(lazy_fd[1]);
            clean_file();
            struct timespec end;
            do {
              FD_ZERO(&read_set);
              FD_SET(lazy_fd[0], &read_set);
              FD_SET(active_fd[0], &read_set);
              int retval = select(active_fd[0]+1, &read_set, NULL, NULL, &tv);
              if(retval == -1){
                perror("select fail");
                exit(EXIT_FAILURE);
              } else if(retval){
                if(FD_ISSET(active_fd[0], &read_set)){
                  int readed = read(active_fd[0], &buffer, sizeof(buffer));
                  if(readed==-1) perror("problem to read pipe");
                  else if(readed){
                    char * timestamp = get_time(start);
                    write_file(buffer, timestamp);
                    free(timestamp);
                  } else {
                    printf("EOF pipe active");
                  }
                } else if (FD_ISSET(lazy_fd[0], &read_set)){
                  int readed = read(lazy_fd[0], &buffer, sizeof(buffer));
                  if(readed==-1) perror("problem to read pipe");
                  else if(readed){
                    char * timestamp = get_time(start);
                    write_file(buffer, timestamp);
                    free(timestamp);
                  } else {
                    printf("EOF pipe lazy");
                  }
                } else {
                  perror("no identified fd in select\n");
                }
              }
              end = timestamp();
            } while((end.tv_sec - start.tv_sec) < 5);
            close(active_fd[0]);
            close(lazy_fd[0]);
            printf("\nExiting...\n");
            kill(pid_one, SIGTERM);
            kill(pid_two, SIGTERM);
            wait(NULL);
            exit(EXIT_SUCCESS);
        }

    }
    return 0;
}
