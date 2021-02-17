#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int freqcount(FILE * f,int * count){
  int c;
  int n = 0;
  while (((c = fgetc(f)) != EOF) && n < 110) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      count[c] += 1;
      n++ ;
    }
  }
  int max = 0;
  int i = 0 ;
  int k ;
  int j = 0;
  //int index;
  while (i < 26){
    if (count[i] > 0){
      j += 1;
      if (count[i] > max){
	max = count[i];
	k = i;
      }
    }
    i++;
  }
  if (j > 3){
    return k;
  }
  else{
    fprintf(stderr,"not enough words\n");
    return k;
  }
}

int breaker(FILE * f){
  int count[26] = {0};
  int key = freqcount(f,count);
  int de = 26-(key - 4) ;
  return de;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int ans = breaker(f);
  if (ans < 26 && ans >= 1){
    fprintf(stdout"%d\n",ans);
  }
  if (ans == 26){
    ans = 0;
    fprintf(stdout,"%d\n",ans);
  }
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
