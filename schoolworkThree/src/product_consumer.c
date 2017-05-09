#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "product_consumer.h"
#include "io_threads.h"

#define PRODUCTOR_REST 1000
#define CONSUMER_REST 1500
#define CONSUMER_A 1
#define LETTER_A 97
#define LETTER_B 98

extern unsigned int run;
extern pthread_t tids[3];

unsigned int MAX_BUFFER_SIZE = 50;
pthread_mutex_t locker;

void * productor(void * undefined_data){
  Data * data = (Data *)undefined_data;

  while(run){
    int number = get_random();
    int error = 0;
    pthread_mutex_lock(&locker);
    if(data->count < MAX_BUFFER_SIZE){
      data->buffer[data->productor_count] = number;
      data->count += 1;
      write_productor(number);
    }else{
      perror("[fatal]: Buffer full, ignoring the produced number");
      error = 1;
    }
    pthread_mutex_unlock(&locker);
    // Only this thread change the memory of max_buffer, is not critical
    if(data->count > data->max_buffer){
      data->max_buffer = data->count;
    }
    if(!error){
      data->productor_count = (data->productor_count+1)%MAX_BUFFER_SIZE;

    }
    error = 0;
    usleep(PRODUCTOR_REST);
  }

  return NULL;
}

void * consumer(void * undefined_data){
  Data * data = (Data *)undefined_data;
  int first = 1;
  char letter = compare_thread();
  MinMax local_minmax;
  while(run){
    int number;
    int read = 0;

    pthread_mutex_lock(&locker);
    if(data->count != 0 && run){
      number = data->buffer[data->consumer_count];
      data->count -= 1;
      data->consumer_count = (data->consumer_count+1)%MAX_BUFFER_SIZE;
      write_consumer(letter, number);
      read = 1;
    }
    pthread_mutex_unlock(&locker);
    if(read){
      update_minmax(&local_minmax, number, &first);
      read = 0;
    }
    usleep(CONSUMER_REST);
  }
  if (letter == LETTER_A) {
    data->minmax_a = local_minmax;
  } else if (letter == LETTER_B) {
    data->minmax_b = local_minmax;
  }
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

void handle_signal_log(){
  pthread_mutex_lock(&locker);
  write_signal_log();
  pthread_mutex_unlock(&locker);
}

char compare_thread(){
    pthread_t tid;

    tid = pthread_self();
    return (pthread_equal(tid,tids[CONSUMER_A]) ? 'a':'b');
}
