#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

void help();
int has_name(char *, char *);
void dir_search(char *, char *, int, int);

int main(int argc, char * argv[]){
  if(argc != 4){
    help();
    exit(EXIT_FAILURE);
  }
  int nivel_max = atoi(argv[3]);
  dir_search(argv[1], argv[2], 0, nivel_max);

  return 0;
}

void help(){
  printf("Using this application is arguments:\n");
  printf("search [DIR] [PATTERN] [NUMBER]\n");
  printf("\t DIR is the path absolute or relative tostart the search for files\n");
  printf("\t PATTERN is the substring to be search in the files in the DIR and sub directories\n");
  printf("\t NUMBER the maximum number of outputs showed to user\n");
}
void dir_search(char * dir, char * pattern, int prints, int max){
  DIR *dp;
  if( (dp = opendir(dir))) {
    struct dirent *ep;
    while( (ep = readdir(dp)) ){
      if( ep->d_type == DT_DIR ) {
        printf("add the subdir\n");
      } else if (ep->d_type ==  DT_REG && has_name(ep->d_name, pattern)){
        printf("read the first 30 B\n");
      }
    }
    closedir(dp);
  } else {
    printf("probem when try open %s", dir);
  }
}
int has_name(char * file, char * pattern){
  return 1;
}
