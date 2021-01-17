#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(char matrix[10][10]){
  int j = 9;
  int k = 0;
  while ( k < j ){
    for (int i = k , l = 0 ; i < j ;i++, l++){
      char a = matrix[k][i];
      char b = matrix[i][j];
      char c = matrix[j][j-l];
      char d = matrix[j-l][k];
      matrix[k][i] = d;
      matrix[i][j] = a;
      matrix[j][j-l] = b;
      matrix[j-l][k] = c;
       }
    k++;
    j--; }
}
