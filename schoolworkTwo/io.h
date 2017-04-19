#ifndef IOFUNCTION
#define IOFUNCTION

/** Read a simple line of input user from standard input
 */
void read_line(char * buffer, size_t size_buffer);

/** Read a content from a pipe (FD) and write in default output file
 */
void read_save_pipe(int df, char* buffer, size_t size_buffer);

#endif
