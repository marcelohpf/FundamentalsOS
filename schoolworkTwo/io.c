#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char FILE_OUTPUT = "./output.txt";

void read_line(char * buffer, size_t size_buffer){
  if(getline(&buffer, &size_buffer, stdin) == -1){
    perror("problem in input user read");
    exit(EXIT_FAILURE);
  } else {
    buffer[strlen(buffer)-1]='\0'; // remove \n from getline read
  }
}

void read_save_pipe(int fd, char * buffer, size_t size_buffer){

  int readed = read(fd, &buffer, size_buffer);

  if(readed==-1) {
    perror("problem to read pipe");
    exit(EXIT_FAILURE);
  } else if(readed){
    char * timestamp = get_time(start);
    FILE* f = fopen(FILE_OUTPUT,"a");
      fprintf(f,"%s: %s\n", timestamp, buffer);
    fclose(f);
    free(timestamp);
  }
}
