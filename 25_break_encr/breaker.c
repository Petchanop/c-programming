#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void filetobig(int * s){
  fprintf(stderr,"File is too big\n");
  for (int i = 1 ; i < 26 ; i++){
    printf("%d\n",count[i]);
  }
  exit(EXIT_FAILURE);
}

int freqcount(FILE * f,int * count){
  int c;
  int n = 0;
  while (((c = fgetc(f)) != EOF)) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      count[c] += 1;
      n++;
      }
   }
  int max = 0;
  int i ;
  int k ;
  for  (i = 0 ; i < 26 ;i++ ){
     if (count[i] > max){
	max = count[i];
	k = i;
      }
     }
  if ( n > 529000){
    return filetobig(count);
  }
  return k;
}

int breaker(FILE * f){
  int count[26] = {0};
  int key = freqcount(f,count);
  if (key < 0){
    fprintf(stderr, "Possibly empty file!\n");
    return EXIT_FAILURE;
  }
  int de;
  if (key < 4){
    de = (26-(4-key))%26;
  }
  else{
    de = (26-(key - 4))%26 ;
  }
  return de;
}
 

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"not enough arguments\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int ans = breaker(f);
  fprintf(stdout,"%d\n",ans);
  
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
