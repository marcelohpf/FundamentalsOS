#ifndef TIMESTAMP
#define TIMESTAMP

/* Obtain a init struct of time and process a amount of time past since this 
 * init struct of time with milisecods of precision
 * return past_time: the time now - init time in string format (0:00.000)
 */
char * get_time(struct timespec);

/* Get a current timestamp since a starting point,
 * use monotonic function of C
   */
struct timespec timestamp();

int random_sleep_time();

#endif
