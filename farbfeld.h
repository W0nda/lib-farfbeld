#ifndef FARBFELD_H_
#define FARBFELD_H_

#include <stdio.h>
#include <stdbool.h>
#include "ffstruct.h"

int ff2jpg(char *colour, bool optimize, short quality, FILE *finput, FILE *foutput);

int ff2png(FILE *finput, FILE *foutput);

int jpg2ff();

int png2ff();

ffstruct ffdata(char *filename);

void ffstruct2ff(ffstruct *ffstruct, char *filename);

#endif 
