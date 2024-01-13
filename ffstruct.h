#ifndef FFSTRUCT_H_
#define FFSTRUCT_H_

typedef struct ffstruct{
	char magic_value[8];
	int width;
	int height;
	char *pixels;
}ffstruct;

#endif
