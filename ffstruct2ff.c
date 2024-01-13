#include "farbfeld.h"
#include "ffstruct.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void ffstruct2ff(ffstruct *ffstruct, char *filename){
	int foutput = open(filename, O_WRONLY);

	write(foutput,ffstruct->magic_value,sizeof(ffstruct->magic_value));
	write(foutput,&ffstruct->width,sizeof(ffstruct->width));
	write(foutput,&ffstruct->height,sizeof(ffstruct->height));

	int px_fieldsize = ffstruct->width * ffstruct->height * 8;
	write(foutput,ffstruct->pixels,px_fieldsize);

	close(foutput);
}
