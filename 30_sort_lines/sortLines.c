#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void printSort(FILE * f){
  char ** line = NULL;
  char * input = NULL;
  size_t sz = 0;
  int i = 0;
  while (getline(&input,&sz, f) >= 0) {
    line = realloc(line,(i+1)*sizeof(*line));
    line[i] = input;
    input = NULL;
    i++;
  }
  free(input);
  sortData(line,i);
  int j =  0 ;
  while (j < i ){
    fprintf(stdout,"%s",line[j]);
    free(line[j]);
    j++;
  }
 }


int main(int argc, char ** argv) {
  if (argc == 1){
    printSort(stdin);
  }
  if (argc > 1){
    for (int i = 2 ; i < argc ; i++){
      FILE * f = fopen(argv[i],"r");
      printSort(f);
      if (f == NULL) {
	perror("Could not open file");
	return EXIT_FAILURE;
      }
     free(f);
    }
  }
  return EXIT_SUCCESS;
}
