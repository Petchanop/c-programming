#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(){
  int array1[]={2,4,8,65,34};
  int array2[]={4,4,4,65,34,56};
  int array3[]={3000,2000,1000,0,-1000};
  int array4[]={33,87,400,65,34};
  int array5[]={3,8,4,5,4};
  int array6[]={-5,-3,-2,-1};
  int array7[]={};
  int array8[]={-1,0};
  int array9[]={4,5,-4,-3,-2,-1,1};
  if (maxSeq(array1,5) != 4){return EXIT_FAILURE;}
  if (maxSeq(array2,6) != 2){return EXIT_FAILURE;}
  if (maxSeq(array9,7) != 5){return EXIT_FAILURE;}
  if (maxSeq(array7,0) != 0){return EXIT_FAILURE;}
  if (maxSeq(array3,5) != 1){return EXIT_FAILURE;}
  return EXIT_SUCCESS;
}
