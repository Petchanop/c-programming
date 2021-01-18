#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);

int main(){
  unsigned x1 = 1;
  unsigned y1 = 0;
  unsigned x2 = -3;
  unsigned y2 = 29;
  if(power(x1,y1) != 1){return EXIT_FAILURE;}
  if(power(y1,x1) != 0){return EXIT_FAILURE;}
  if(power(y1,y1) != 0){return EXIT_FAILURE;}
  if(power(x2,y2) != -68630377364883){return EXIT_FAILURE;}
  else{
    return EXIT_SUCCESS;
  }
}
