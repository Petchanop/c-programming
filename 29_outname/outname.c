#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char * outFileName;
  outFileName =  malloc((strlen(inputName)+7) * sizeof(*inputName));
  strcpy(outFileName, inputName);
  strcat(outFileName, ".count");
  return outFileName;
}

