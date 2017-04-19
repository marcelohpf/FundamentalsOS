#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "timestamp.h"

const char FILE_OUTPUT[] = "./output.txt";

void read_line(char * buffer, size_t size_buffer){
  if(getline(&buffer, &size_buffer, stdin) == -1){
    perror("problem in input user read");
    exit(EXIT_FAILURE);
  } else {
    buffer[strlen(buffer)-1]='\0'; // remove \n from getline read
  }
}

void clean_file(){
  FILE* f = fopen(FILE_OUTPUT,"w");
  fclose(f);
}
void write_file(char *content, char * timestamp){
  FILE* file = fopen(FILE_OUTPUT,"a");
  if(file!=NULL){
    fprintf(file,"%s: %s\n", timestamp, content);
    fclose(file);
  } else {
    perror("Not able to open the file now");
  }
}

void lazy_pipe(int fd, char *buffer, size_t buffer_size, int i, struct timespec start){
  char * message = get_time(start);
  sprintf(buffer, "%s: Mensagem %.2d do filho dorminhoco", message, i);
  free(message);
  write(fd, buffer, buffer_size);
  sleep(random_sleep_time());
}


void active_pipe(int fd, char *buffer, size_t buffer_size, int i, struct timespec start){
  char *message = (char*) malloc(buffer_size);
  read_line(message, sizeof(message));
  char * timestamp = get_time(start);
  sprintf(buffer, "%s: Mensagem %.2d do usuário: <%s>", timestamp, i, message);
  write(fd, buffer,buffer_size);
  free(timestamp);
  free(message);
}

void write_loaded_pipe(int readed, char* buffer, struct timespec start){
  if(readed==-1) perror("problem to read pipe");
  else if(readed){
    char * timestamp = get_time(start);
    write_file(buffer, timestamp);
    free(timestamp);
  } else {
    printf("EOF pipe active");
  }

}
