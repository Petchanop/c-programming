#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


kvpair_t * makekvpair(char * f){
  kvpair_t * pair = malloc((size_t) sizeof(*pair));
  int k = 0;
  char * key;
  key = strtok(f,"=");
  while (key != NULL) {
    if (k == 0){
      pair->key = key;
    }
    if (k == 1){
      pair->value = key;
    }
    key = strtok(NULL,"=");
    k++;
  }
  strncat(pair->key,"\0",1);
  strncat(pair->value,"\0",1);
   return pair;
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
