#include <stdio.h>
#include <stdlib.h>
#include "product_consumer.h"
#include "io_threads.h"

char * file_name;
void end_write_log(FILE * log_file, Data data){

  fprintf(log_file, "[aviso]: Maior numero gerado: %d\n", data.minmax.maximum);
  fprintf(log_file, "[aviso]: Menor numero gerado: %d\n", data.minmax.maximum);
  fprintf(log_file, "[aviso]: Maior ocupacao de buffer: %d\n", data.max_buffer);
  fprintf(log_file, "[aviso]: Aplicacao encerrada.\n");

}

void write_signal_log(){
  FILE * log = open_file(file_name);
  fprintf(stdout, "[aviso]: Termino solicitado. Aguardando threads...\n");
  fprintf(log, "[aviso]: Termino solicitado. Aguardando threads...\n");
  fclose(log);
}

FILE * create_file_args(int argc, char ** argv){
  if(argc == 2){
    // clear file if possible
    file_name = argv[1];
    FILE * file = fopen(file_name, "w");
    fclose(file);
    return open_file(file_name);
  }
  perror("[error]: deve ser passado 1 parametro com o nome do arquivo");
  exit(EXIT_FAILURE);
}

FILE * open_file(char * name){
  FILE * file = fopen(name, "a");
  if(file == NULL){
    perror("[fatal]: impossible to open file");
    exit(EXIT_FAILURE);
  }
  return file;
}

void write_productor(int number){
  FILE * log = open_file(file_name);
  fprintf(log,"[produtor]: %d\n",number);
  fclose(log);
}
