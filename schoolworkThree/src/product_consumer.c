#include <unistd.h>
#include <stdio.h>

extern int run;
void producer(void* data){
  while(run){
    printf("ola");
    usleep(150);
  }
  printf("fim consumer");

}

void consumer(void* data){
  while(run){
    printf("oi");
    usleep(150);
  }
  printf("fim consumer");
}
