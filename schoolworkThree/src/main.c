#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "product_consumer.h"
#define THREADS_NUMBER 3
int run = 1;

void user_interrupt_handle(int signal_received){
  printf("[aviso]: Termino solicitado. Aguardando threads...\n");
  run=0;
  signal(SIGINT, user_interrupt_handle);
}

int main(){
  signal(SIGINT, user_interrupt_handle);
  srandom(time(NULL));
  pthread_attr_t attr[3];
  pthread_t tid[3];
  void * (*functions[])(void *data) = {productor, consumer, consumer};
  void * result;
  Data data;
  data.maxBuffer = 0;
  data.productor_count=0;
  data.consumer_count = 0;
  int thread;

  for(thread = 0;thread<THREADS_NUMBER; ++thread){

    if(pthread_attr_init(&attr[thread])!=0){
      perror("problem with thread initialization of attributes");
      exit(EXIT_FAILURE);
    }

  }

  for(thread = 0;thread < THREADS_NUMBER; ++thread){

    if(pthread_create(&tid[thread], &attr[thread],
          functions[thread], &data)!=0){
      perror("problem with thread creation consumer 1");
      exit(EXIT_FAILURE);
    }

  }

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
  printf("\n%d\n",data.maxBuffer);
  printf("min: %d, max: %d\n",data.minmax.minimum,data.minmax.maximum);
  return 0;
}
