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
  unsigned int productor_count;
  unsigned int consumer_count;
  unsigned int max_buffer;
  unsigned int count;
} Data;

void* productor(void *);
void* consumer(void *);
void update_minmax(MinMax *, int, int*);
int get_random();
void handle_signal_log();
char compare_thread();
#endif
