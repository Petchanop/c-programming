#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * makekvpair(char * f){
  kvpair_t * pairs;
  pairs = malloc((size_t) sizeof(*pairs));
  char * key = strtok(f,"=");
  int k = 0;
  while (key != NULL) {
    if (k == 0){
      pairs->key = key;

    }
    if (k > 0){
      pairs->value = key;

    }
    key = strtok(NULL,"=");

    k++;
  }
  return pairs;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname,"r");
  char * input = NULL;
  kvpair_t * pairs = NULL;
  kvarray_t * read = malloc((size_t)sizeof(*read));
  size_t sz = 0;
  read->names = NULL;
  read->keyn = 0;
  while (getline(&input,&sz, f) >= 0) {
    pairs = makekvpair(input);
    read->names  = realloc(read->names,(read->keyn+1)*sizeof(*read->names));
    read->names[read->keyn] = pairs;
    input = NULL;
    read->keyn++;
  }
  free(input);
  fclose(f);
  return read;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0 ;i<pairs->keyn;i++){
    free(pairs->names[i]->key);
    free(pairs->names[i]);
  }
  free(pairs->names);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0 ; i < pairs->keyn ; i++){
    printf("%s\n",pairs->names[i]->key);
    printf("%s\n",pairs->names[i]->value);
  }             
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  kvpair_t * curr; 
   for (int i = 0 ; i < pairs->keyn ; i++ ){
    curr = pairs->names[i];
    if (!strcmp(curr->key,key)){
      return  curr->value ;
    }
  }
  return NULL;     
}
