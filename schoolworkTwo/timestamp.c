#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "timestamp.h"
#define NANO_TO_MILISECONDS 1000000


char * get_time(struct timespec start){

  struct timespec end = timestamp();
  char * message = (char*) malloc(sizeof(char)*20);

  long total_time = (end.tv_sec-start.tv_sec)*1000 + (end.tv_nsec-start.tv_nsec)/NANO_TO_MILISECONDS;

  int miliseconds = total_time%1000;
  int seconds = total_time/1000;
  seconds %= 60;

  int minutes = total_time / 60000;

  sprintf(message, "%d:%.2d.%.3d",minutes, seconds%60, miliseconds);

  return message;

}
struct timespec timestamp(){

  struct timespec now;

  if(clock_gettime(CLOCK_MONOTONIC, &now) == -1){
    perror("problem with get_time from clock");
    exit(EXIT_FAILURE);
  }

  return now;

}

int random_sleep_time(){
  long factor = RAND_MAX/3;
  long random = rand();
  if(random < factor) return 0;
  else if(random > factor*2) return 1;
  else return 2;
}
