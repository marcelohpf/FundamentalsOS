#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "product_consumer.h"
#include "io_threads.h"

#define THREADS_NUMBER 3

extern char * file_name;

unsigned int run = 1;
pthread_t tids[THREADS_NUMBER];

Data init_data();
void user_interrupt_handle(int signal_received);
int max_value(MinMax max_a, MinMax max_b);
int min_value(MinMax min_a, MinMax min_b);

int main(int argc, char* argv[]){

  signal(SIGINT, user_interrupt_handle);
  create_file_args(argc, argv);
  pthread_attr_t attr[3];
  int thread;

  for(thread = 0;thread<THREADS_NUMBER; ++thread){

    if(pthread_attr_init(&attr[thread])!=0){
      perror("problem with thread initialization of attributes");
      exit(EXIT_FAILURE);
    }

  }

  Data data = init_data();
  void * (*functions[])(void *data) = {productor, consumer, consumer};

  for(thread = 0;thread < THREADS_NUMBER; ++thread){

    if(pthread_create(&tids[thread], &attr[thread],
          functions[thread], &data)!=0){
      perror("problem with thread creation consumer 1");
      exit(EXIT_FAILURE);
    }
  }

  void * result;
  for(thread = 0; thread < THREADS_NUMBER; ++thread){

    if(pthread_join(tids[thread], &result)!=0){
      perror(result);
      exit(EXIT_FAILURE);
    }

  }
  free(result);


  for(thread = 0; thread < THREADS_NUMBER; ++thread){

    if(pthread_attr_destroy(&attr[thread])!=0){
      perror("problem with destruction of thread attributes");
      exit(EXIT_FAILURE);
    }

  }

  MinMax minmax;
  minmax.minimum = min_value(data.minmax_a, data.minmax_b);
  minmax.maximum = max_value(data.minmax_a, data.minmax_b);
  FILE * log =  open_file(file_name);
  end_write_log(log, data.max_buffer, minmax);
  fclose(log);
  end_write_log(stdout, data.max_buffer, minmax);

  return 0;
}

void user_interrupt_handle(int signal_received){
  run=0;
  handle_signal_log();
  signal(SIGINT, user_interrupt_handle);
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

int max_value(MinMax max_a, MinMax max_b){
  return (max_a.maximum > max_b.maximum ? max_a.maximum: max_b.maximum);
}
int min_value(MinMax min_a, MinMax min_b){
  return (min_a.minimum < min_b.minimum ? min_a.minimum: min_b.minimum);
}
