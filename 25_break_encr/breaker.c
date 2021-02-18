#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int freqcount(FILE * f){
  int count[26] = {0};
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

   if (k < 4){
    de = (26-(4-k))%26;
 }
   else{
   de = (26-(k- 4))%26 ;
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
  int ans = freqcount(f);
  print("%d\n",ans);

  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
