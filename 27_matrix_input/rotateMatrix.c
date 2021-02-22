#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void rotate(char matrix[10][10]){
  int j = 9;
  int k = 0;
  while ( k < j ){
    for (int i = k , l = 0 ; i < j ;i++, l++){
      char a = matrix[k][i];
      char b = matrix[i][j];
      char c = matrix[j-l][j-l];
      char d = matrix[j-l][k];
      matrix[k][i] = d;
      matrix[i][j] = a;
      matrix[j-l][j-i] = b;
      matrix[j-i][k] = c;
    }
    k++;
    j--; }
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"should takes 1 arguments\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  char  matrix[10][10];
  int c;
  int i = 0;

  while ((c = (char)fgetc(f))!= EOF){
    i++;
  }
  if (i < 9){
    fprintf(stderr,"Few lines\n");
    exit(EXIT_FAILURE);
  }
  if (i > 9){
    fprintf(stderr,"lines too long\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < 10; i++){
    for (int  j = 0; j < 10; j++){
      c = fgetc(f);
      if (c == '\n') c = fgetc(f);
      matrix[i][j] = c;
    }
  }


  rotate(matrix);
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }


  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
