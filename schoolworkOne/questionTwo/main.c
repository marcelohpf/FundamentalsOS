#include <stdio.h>
#include <stdlib.h>

/* That assumes the execution have the ./dir/name.out 
 * search and find the last / to get the name
 * */
char* basename(char* name){
  int move = 0;
  int last_move = 0;
  int i = 0;
  while(name[i] != '\0'){
    if(name[i] == '/'){
      move = i;
    }
    i++;
  }

  return &name[move+1];

}
/* This is a simple input of argument in execution of terminal */
int main(int args, char* argv[]){

  int counter_argv=0;
  printf("# de parametros: %d\n", args-1);

  char* executable = basename(argv[counter_argv++]);
  printf("Nome do executavel: %s\n", executable);

  for(;counter_argv < args; counter_argv++){
    printf("Parametro #%d: %s\n", counter_argv, argv[counter_argv]);
  }

  return 0;
}
