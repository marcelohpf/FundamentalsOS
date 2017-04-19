#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/select.h>
#include <string.h>

int main(){
    int lazy_fd[2] = { -1, -1};
    int active_fd[2] = {-1, -1};
    char buffer[100];
    char buffer2[100];
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    fd_set read_set;

    if(pipe(lazy_fd) == -1 || pipe(active_fd) == -1){
        perror("pipe initialization error");
        exit(EXIT_FAILURE);
    }
    printf("[%d, %d]\n", lazy_fd[0], active_fd[0]);


    pid_t pid_one;
    pid_t pid_two;
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
        sleep(1);
        write(lazy_fd[1], "Encreten o ba ta t ", sizeof(buffer));
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
            char teste[1000];
            int i;
            for(i=0;i<6;i++){
            scanf("%s",teste);
            write(active_fd[1], teste,sizeof(buffer));
            }
            close(active_fd[1]);
            printf("exited 2\n");
            exit(EXIT_SUCCESS);
        } else {
            close(active_fd[1]);
            close(lazy_fd[1]);
            int i=0;
            FILE* f = fopen("/tmp/a.txt","w");
            fprintf(f,"New execution\n");
            fclose(f);

            while(1){
            FD_ZERO(&read_set);
            FD_SET(lazy_fd[0], &read_set);
            FD_SET(active_fd[0], &read_set);
                int retval = select(active_fd[0]+1, &read_set, NULL, NULL, &tv);
                //printf("{%d}",retval);
                if(retval == -1){
                    perror("select fail");
                    exit(EXIT_FAILURE);
                } else if(retval){
                    if(FD_ISSET(active_fd[0], &read_set)){
                      int readed = read(active_fd[0], &buffer, sizeof(buffer));
                     if(readed==-1) perror("problem to read pipe");
                     else if(readed){
                        FILE* f = fopen("/tmp/a.txt","a");
                        fprintf(f,"(%s)\n",buffer);
                        fclose(f);
                        i++;
                     } else {
                        printf("EOF pipe active");
                     }
                    } else if (FD_ISSET(lazy_fd[0], &read_set)){
                       int readed = read(lazy_fd[0], &buffer2, sizeof(buffer2));
                       if(readed==-1) perror("problem to read pipe");
                       else if(readed){
                        FILE* f = fopen("/tmp/a.txt","a");
                        fprintf(f,"(%s)\n",buffer2);
                        fclose(f);
                        i++;
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
