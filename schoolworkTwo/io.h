#ifndef IOFUNCTION
#define IOFUNCTION

/** Read a simple line of input user from standard input
 */
void read_line(char * buffer, size_t size_buffer);


/** Write to default file the outputs */
void write_file(char* content, char* timestamp);

#endif
