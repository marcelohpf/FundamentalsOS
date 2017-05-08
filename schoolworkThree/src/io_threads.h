#ifndef IOTHREAD
#define IOTHREAD

#include <stdio.h>
#include "product_consumer.h"

extern char * file_name;
void end_write_log(FILE * , Data);
void write_signal_log();
void write_productor(int );

FILE * create_file_args(int, char **);
FILE * open_file(char *);
#endif
