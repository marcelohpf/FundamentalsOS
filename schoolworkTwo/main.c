#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/select.h>
#include <string.h>
#include <time.h>
#include "timestamp.h"
#include "io.h"
#define MAX_BUFFER 500

int main(){
    int lazy_fd[2] = { -1, -1};
    int active_fd[2] = {-1, -1};
    char buffer[MAX_BUFFER];
    char buffer2[MAX_BUFFER];
    fd_set read_set;

    if(pipe(lazy_fd) == -1 || pipe(active_fd) == -1){
        perror("pipe initialization error");
        exit(EXIT_FAILURE);
    }

    pid_t pid_one;
    pid_t pid_two;
    struct timespec start = timestamp();
    pid_one = fork();
    if(pid_one == -1){
        perror("fork call error");
        exit(EXIT_FAILURE);
    }
    if(pid_one == 0){
        printf("child 1: %d\n",pid_one);
        close(lazy_fd[0]);
        int i;
        for(i=0; i<10; i++){
          sleep(random_sleep_time());
          char * message = get_time(start);
          sprintf(buffer, "%s: Mensagem %.2d do filho dorminhoco", message, i);
          free(message);
          write(lazy_fd[1], buffer, sizeof(buffer));
        }
        close(lazy_fd[1]);
        printf("exited 1\n");
        exit(EXIT_SUCCESS);
    } else {
        pid_two = fork();
        if(pid_two == -1){
            perror("fork call error");
            exit(EXIT_FAILURE);
        }
        if(pid_two == 0){
            printf("child 2: %d\n",pid_two);
            close(active_fd[0]);
            char teste[MAX_BUFFER-40]; // Remove necessary characters from possible message
            int i;
            for(i=0;i<6;i++){
              read_line(teste, sizeof(teste));
              char * timestamp = get_time(start);
              sprintf(buffer, "%s: Mensagem %.2d do usuário: <%s>", timestamp, i, teste);
              write(active_fd[1], buffer,sizeof(buffer));
            }
            close(active_fd[1]);
            printf("exited 2\n");
            exit(EXIT_SUCCESS);
        } else {
            struct timeval tv;
            tv.tv_sec = 2;
            tv.tv_usec = 0;
            close(active_fd[1]);
            close(lazy_fd[1]);
            int i=0;
            FILE* f = fopen("./output.txt","w");
            fprintf(f,"New execution\n");
            fclose(f);

            while(1){
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
                       int readed = read(lazy_fd[0], &buffer2, sizeof(buffer2));
                       if(readed==-1) perror("problem to read pipe");
                       else if(readed){
                        char * timestamp = get_time(start);
                        write_file(buffer2, timestamp);
                        free(timestamp);
                     } else {
                        printf("EOF pipe lazy");
                     }
                    } else {
                        perror("no identified fd in select\n");
                    }
                } else {
                  //sleep(1);
                  //printf("[%d, %d]\n", lazy_fd[0], active_fd[0]);
                  i++;
                }
            }
            printf("\n");
            close(active_fd[0]);
            close(lazy_fd[0]);
//            fclose(f);
            wait(NULL);
            exit(EXIT_SUCCESS);
        }

    }
    return 0;
}
