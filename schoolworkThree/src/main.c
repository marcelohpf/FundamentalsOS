#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "product_consumer.h"
#define THREADS_NUMBER 3
int run = 1;


int main(){
  pthread_attr_t attr[3];
  pthread_t tid[3];
  void * (*functions[])(void *data) = {productor, consumer, consumer};
  void * result;
  Data data;
  data.count =0;
  data.maxBuffer=0;
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

  sleep(1);
  printf("\n\n\n\n\n\n\n\n\nn\\n\nn\n\n\n\n\n\n\n\n\n\n\n\n");
  run=0;
  for(thread = 0;thread < THREADS_NUMBER; ++thread){

    if(pthread_join(tid[thread], &result)!=0){
      perror(result);
      exit(EXIT_FAILURE);
    }

  }

  return 0;
}
