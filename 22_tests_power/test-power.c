#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);

int main(){
  unsigned x1 = 1;
  unsigned y1 = 0;
  unsigned x2 = 10000;
  unsigned y2 = 2;
  unsigned x3 = -2;

  if(power(y1,y1) != 0){return EXIT_FAILURE;}
  if(power(2,"1") != 2 ){return EXIT_FAILURE;} 

    return EXIT_SUCCESS;
 
}
