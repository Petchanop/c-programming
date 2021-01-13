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
  int *arrayar[]={array1,array2,array3,array4,array5,array6,array7,array8,array9};
  int arraylen[]={5,6,5,5,5,4,0,2,7};
  int arrayseq[]={4,2,1,3,2,1,0,1,5};
  for (int i=0; i<9; i+1){
    if (maxSeq(arrayar[i],arraylen[i])!= arrayseq[i]){
      return EXIT_FAILURE;
    }
  }
    return EXIT_SUCCESS;
}
