#ifndef PCTHREAD
#define PCTHREAD

struct MinMax{
  int maximum;
  int minimum;
};
struct Data{
  struct MinMax data;
  int buffer[50];
  int count;
  int maxBuffer;
};

void producer(void *data);
void consumer(void *data);
#endif
