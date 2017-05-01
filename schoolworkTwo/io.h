#ifndef IOFUNCTION
#define IOFUNCTION

/** Read a simple line of input user from standard input
 */
void read_line(char * buffer, size_t size_buffer);


/** Write to default file the outputs */
void write_file(char* content, char* timestamp);

void lazy_pipe(int fd, char *buffer, size_t buffer_size, int i, struct timespec start);

void active_pipe(int fd, char *buffer, size_t buffer_size, int i, struct timespec start);

void clean_file();

void write_loaded_pipe(int readed, char* buffer, struct timespec start);
#endif
