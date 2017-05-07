#include <unistd.h>
#include <stdio.h>
#define PRODUCTOR_REST 100
#define CONSUMER_REST 150

extern int run;
void* productor(void* data){
  while(run){
    printf("ola");
    usleep(PRODUCTOR_REST);
  }
  printf("fim consumer");
  return NULL;
}

void* consumer(void* data){
  while(run){
    printf("oi");
    usleep(CONSUMER_REST);
  }
  printf("fim consumer");
  return NULL;
}
