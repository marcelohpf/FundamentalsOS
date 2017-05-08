#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "product_consumer.h"
#include "io_threads.h"
#define THREADS_NUMBER 3
int run = 1;
extern char * file_name;
void user_interrupt_handle(int signal_received){
  run=0;
  handle_signal_log();
  signal(SIGINT, user_interrupt_handle);
}
Data init_data();
int main(int argc, char* argv[]){

  signal(SIGINT, user_interrupt_handle);

  pthread_attr_t attr[3];
  int thread;

  for(thread = 0;thread<THREADS_NUMBER; ++thread){

    if(pthread_attr_init(&attr[thread])!=0){
      perror("problem with thread initialization of attributes");
      exit(EXIT_FAILURE);
    }

  }

  FILE * log =  create_file_args(argc, argv);
  Data data = init_data(log);
  pthread_t tid[3];
  void * (*functions[])(void *data) = {productor, consumer, consumer};

  for(thread = 0;thread < THREADS_NUMBER; ++thread){

    if(pthread_create(&tid[thread], &attr[thread],
          functions[thread], &data)!=0){
      perror("problem with thread creation consumer 1");
      exit(EXIT_FAILURE);
    }

  }

  void * result;
  for(thread = 0;thread < THREADS_NUMBER; ++thread){

    if(pthread_join(tid[thread], &result)!=0){
      perror(result);
      exit(EXIT_FAILURE);
    }

  }

  for(thread = 0;thread<THREADS_NUMBER; ++thread){

    if(pthread_attr_destroy(&attr[thread])!=0){
      perror("problem with destruction of thread attributes");
      exit(EXIT_FAILURE);
    }

  }
  end_write_log(log, data);
  end_write_log(stdout, data);
  fclose(log);
  return 0;
}
Data init_data(){
  Data data;
  data.max_buffer = 0;
  data.productor_count=0;
  data.consumer_count = 0;
  data.count = 0;
  srandom(time(NULL));
  return data;
}
