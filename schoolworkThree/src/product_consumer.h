#ifndef PCTHREAD
#define PCTHREAD

typedef struct MinMax{
  int maximum;
  int minimum;
} MinMax;
typedef struct Data{
  MinMax data;
  int buffer[50];
  int count;
  int maxBuffer;
} Data;

void* productor(void *data);
void* consumer(void *data);
#endif
