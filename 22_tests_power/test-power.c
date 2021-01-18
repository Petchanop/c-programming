#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);

int main(){
  if(power(1,0) != 1){return EXIT_FAILURE;} 
  if(power(-1,2) != 1){return EXIT_FAILURE;}
  if(power(2,22) != 4194304){return EXIT_FAILURE;}
  if(power(0,0) != 1){return EXIT_FAILURE;}
  return EXIT_SUCCESS;
 
}
