#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sin.h"

void help();
int main(int argc, char* argv[]){
    if(argc != 3){
      printf("É exigido 2 parametros\n");
      help();
      exit(EXIT_FAILURE);
    }else if(strcmp(argv[1],"-a")==0){
      printf("arc_seno (%s) = %lf\n",argv[2], arc_sin(atof(argv[2])));
    }else if(strcmp(argv[1],"-s")==0){
      printf("seno (%s) = %lf\n",argv[2], sin(atof(argv[2])));
    } else {
      printf("As operações aceitas são -a|-b");
    }
    return 0;
}

void help(){
  printf("trigonometry [-a|-s] [value]");
  printf("\n\t-a arcoseno\n\t-s seno\n");
  printf("\tvalue valor do angulo em RAD, utilize '.' ao invés de ',' Ex.: 0.221\n");
}

