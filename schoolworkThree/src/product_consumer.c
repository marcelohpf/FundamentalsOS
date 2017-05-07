#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "product_consumer.h"

#define PRODUCTOR_REST 100
#define CONSUMER_REST 150

extern int run;
unsigned int MAX_BUFFER_SIZE = 50;
pthread_mutex_t locker;

void * productor(void * undefined_data){
  Data * data = (Data *)undefined_data;

  while(run){
    pthread_mutex_lock(&locker);
    int number = get_random();
    if(data->count < MAX_BUFFER_SIZE){
      data->buffer[data->productor_count] = number;
      data->count += 1;
      data->productor_count = (data->productor_count+1)%MAX_BUFFER_SIZE;
    }else{
      perror("[fatal]: Buffer full");
    }
    if(data->count > data->maxBuffer) data->maxBuffer = data->count;
    printf("[produtor]: %d\n",number);
    pthread_mutex_unlock(&locker);
    usleep(PRODUCTOR_REST);
  }

  printf("fim productor");
  return NULL;
}

void * consumer(void * undefined_data){
  Data * data = (Data *)undefined_data;
  int first =1;
  while(run || data->count){
    int number;
    pthread_mutex_lock(&locker);
    if(data->count != 0){
      number = data->buffer[data->consumer_count];
      data->consumer_count = (data->consumer_count+1)%MAX_BUFFER_SIZE;
      data->count -= 1;
      update_minmax(&data->minmax, number, &first);
      printf("[consumer]: %d\n",number);
    }
    pthread_mutex_unlock(&locker);
    usleep(CONSUMER_REST);
  }
  printf("fim consumer");
  return NULL;
}

/* Generate a random number in interval of X=RAND_MAX/2
 * -X < random_number < X
 */
int get_random(){
  long random_number = random();
  return random_number - (RAND_MAX/2);
}
void update_minmax(MinMax * values, int number, int * first){
  if(*first){
    values->minimum = number;
    values->maximum = number;
    *first -= 1;
  } else {
    values->maximum = (values->maximum < number ? number:values->maximum);
    values->minimum = (values->minimum > number ? number:values->minimum);
  }
}
