#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

one_count_t  * addOneCount (const char * name){
  one_count_t  * add ;
  add = malloc(sizeof(*add));
  add->name = name;
  add->count = 1;
  return add;
}

counts_t * createCounts(void) {
  //WRITE ME
  counts_t * names = malloc(sizeof(*names));
  names->values = NULL;
  names->size = 0;
  names->unknown = 0;
 return names;
}

void addCount(counts_t * c, const char * name) {
  //WRITE ME
  int j = 0;
  if (name == NULL){
    c->unknown++;
  }
  else{
  if (c->values != NULL){
    for (int i = 0 ; i < c->size ; i++){
      if (!strcmp(c->values[i]->name,name)){
	c->values[i]->count++;
       }
      else{
	j++;
      }
    }
  }
  if (j == c->size){
    one_count_t  * add = NULL;
    add = addOneCount(name);   
    c->values = realloc(c->values,(c->size+1)*sizeof(*c->values));
    c->values[c->size] = add;
    c->size++;
    }
  }
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for (int i = 0 ; i < c->size ; i++){
    if (c->values[i]->name != NULL){
    printf("%s: %d\n",c->values[i]->name,c->values[i]->count);
  }
 }
   printf("<unknown> : %d\n",c->unknown);
  fclose(outFile); 
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i=0 ; i < c->size ; i++){
    free(c->values[i]);
  }
  free(c->values);
  free(c);    
}
