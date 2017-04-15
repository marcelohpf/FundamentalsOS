#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(){
  int lazy_fd[2];
  int active_fd[2];
  char buffer;
  if(pipe(lazy_fd) == -1 || pipe(active_fd) == -1){
    perror("pipe initialization error");
    exit(EXIT_FAILURE);
  }
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
    for(i=0;i<5;i++){
    write(lazy_fd[1], "E cre en o ba ta t ", 20);
    }
    close(lazy_fd[0]);
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
      for(i=0;i<5;i++){
      scanf("%s",teste);
      write(active_fd[1], teste, strlen(teste));
      }
      close(active_fd[1]);
      exit(EXIT_SUCCESS);
    } else {
      close(active_fd[1]);
      close(lazy_fd[1]);
      int i=0;
      FILE* f = fopen("/tmp/a.txt","w");
      for(;i<5;i++){
      while(read(lazy_fd[0], &buffer, 1) >0)
       fprintf(f,"%c",buffer);
      while(read(active_fd[0], &buffer, 1) >0)
        fprintf(f,"%c",buffer);
      }
      printf("\n");
      close(active_fd[0]);
      close(lazy_fd[0]);
      fclose(f);
      wait(NULL);
      exit(EXIT_SUCCESS);
    }

  }
  return 0;
}
