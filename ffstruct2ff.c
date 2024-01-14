#include "farbfeld.h"
#include "ffstruct.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int reverseEndianness(int val)
{
    return (val << 24) |
          ((val <<  8) & 0x00ff0000) |
          ((val >>  8) & 0x0000ff00) |
          ((val >> 24) & 0x000000ff);
}

void ffstruct2ff(ffstruct *ffstruct, char *filename){
	int foutput = open(filename, O_WRONLY);

	write(foutput,ffstruct->magic_value,sizeof(ffstruct->magic_value));

	int width = reverseEndianness(ffstruct->width);
	int height = reverseEndianness(ffstruct->height);
	write(foutput,&width,sizeof(width));
	write(foutput,&height,sizeof(height));

	int px_fieldsize = ffstruct->width * ffstruct->height * 8;
	write(foutput,ffstruct->pixels,px_fieldsize);

	close(foutput);
}
