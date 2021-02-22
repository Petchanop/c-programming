#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_SIZE 10

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

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Invalid arguments\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int c = fgetc(f);
  if(c == EOF){
    fprintf(stderr,"Usage: Empty File\n");
    return EXIT_FAILURE;
  }
  char  matrix[10][10];
  int i = 0;
  int j = 0;
  while (c != EOF){

    if (i > 9){
      fprintf(stderr,"Too many rows\n");
      exit(EXIT_FAILURE);
    }
    if (j == 10){
      i++;
      j = 0;
      if (c != '\n'){
	fprintf(stderr,"Line Too Long!");
	exit(EXIT_FAILURE);
      }
    }
    else{
      if (c == '\n'){
	fprintf(stderr,"Less column");
	exit(EXIT_FAILURE);
      }
      matrix[i][j] = c;
      j++;
    }
    c = fgetc(f);
  }

  fclose(f);

  if (i < 9){
    fprintf(stderr,"Few lines\n");
    exit(EXIT_FAILURE);
  }
  rotate(matrix);
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}
