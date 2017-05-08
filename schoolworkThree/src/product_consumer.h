#ifndef PCTHREAD
#define PCTHREAD
#define BUFFER_SIZE 50

extern unsigned int MAX_BUFFER_SIZE;

typedef struct MinMax{
  int maximum;
  int minimum;
} MinMax;

typedef struct Data{
  MinMax minmax;
  int buffer[BUFFER_SIZE];
  int productor_count;
  int consumer_count;
  int max_buffer;
  int count;
} Data;

void* productor(void *);
void* consumer(void *);
void update_minmax(MinMax *, int, int*);
int get_random();
void handle_signal_log();
#endif
