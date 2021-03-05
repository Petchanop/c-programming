#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  FILE * f = fopen(filename,"r");
  char ** line = NULL;
  char * input = NULL;
  size_t sz = 0;
  size_t i = 0;
  while (getline(&input,&sz, f) >= 0) {
    line = realloc(line,(i+1)*sizeof(*line));
    line[i] = input;
    input = NULL;
    char* n = strchr(line[i],'\n');
    if(n != NULL) *n='\0';
    i++;
  }
  free(input);
  counts_t * testCounts= createCounts();
  int j =  0 ;
  while (j < i ){
     if (lookupValue(kvPairs,line[j]) != NULL){
       addCount(testCounts,lookupValue(kvPairs,line[j]));
    }
    else{
      testCounts->unknown++;
    }
     free(line[j]);
    j++;
  }
  free(line);
  fclose(f);
  return testCounts;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)
  for (int i = 2 ; i < argc ; i++){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c;
    c = countFile(argv[i],kv);  
    //compute the output file name from argv[i] (call this outName)
    char * cName = computeOutputFileName(argv[i]);    
    //open the file named by outName (call that f)
    FILE * f = fopen(cName,"w"); 
    //print the counts from c into the FILE f
    printCounts(c,f);  
    //close f
  
    
    //free the memory for outName and c
    free(cName);
    freeCounts(c);
  }
 //free the memory for kv
    freeKVs(kv);
  
  return EXIT_SUCCESS;
}
