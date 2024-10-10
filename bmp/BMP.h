

#ifndef BMP_H
#define BMP_H

#include <stdio.h>
#include <stdlib.h>
#include "matrix/matrix.h"

extern FILE *image;
extern int width;
extern int height;
extern int bitcount;
extern int bitoffset;
extern int w;
extern const char* name1; 



typedef struct {
   unsigned int width;
   unsigned int height;
   unsigned int planes;
   unsigned short bitcount;
   unsigned int bitoffset;
} HEADER;



void header(const char* name);
int***  pixel();
void write(int *** arr);
#endif
