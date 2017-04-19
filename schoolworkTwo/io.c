#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char FILE_OUTPUT[] = "./output.txt";

void read_line(char * buffer, size_t size_buffer){
  if(getline(&buffer, &size_buffer, stdin) == -1){
    perror("problem in input user read");
    exit(EXIT_FAILURE);
  } else {
    buffer[strlen(buffer)-1]='\0'; // remove \n from getline read
  }
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
