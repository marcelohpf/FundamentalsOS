#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

void help();
double execute_dynamic_load(double, char*);

int main(int argc, char* argv[]){
    if(argc != 3){
      printf("É exigido 2 parametros\n");
      help();
      exit(EXIT_FAILURE);
    }else if(strcmp(argv[1],"-a")==0){
      printf("arc_seno (%s) = %lf\n", argv[2], execute_dynamic_load(atof(argv[2]), "arc_sin"));
    }else if(strcmp(argv[1],"-s")==0){
      printf("seno (%s) = %lf\n", argv[2], execute_dynamic_load(atof(argv[2]), "sin"));
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

double execute_dynamic_load(double rads, char * function_name){
  void * handle = dlopen("libseno.so", RTLD_LAZY);
  if(!handle) {
    printf("%s\n", dlerror());
    exit(EXIT_FAILURE);
  }
  dlerror();
  double (*function)(double);
  *(void **) (&function) = dlsym(handle, function_name);
  char *error = dlerror();
  if(error != NULL){
    printf("%s\n", error);
    exit(EXIT_FAILURE);
  }

  double result = (*function)(rads);
  dlclose(handle);
  return result;
}
