// Get the data content and put them into
// a ff struct

#include "farbfeld.h"
#include "util.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

ffstruct ffdata(char *filename){

	int file = open(filename, O_RDONLY);

	ffstruct ff_file;
	char magic_value[8] = {'f','a','r','b','f','e','l','d'};
	strcpy(ff_file.magic_value, magic_value);
	
	lseek(file, 8, SEEK_SET);
	read(file, &ff_file.width, 4);
	read(file, &ff_file.height, 4);

	//resolve endianness problem
	ff_file.width = reverseEndianness(ff_file.width);
	ff_file.height = reverseEndianness(ff_file.height);

	int px_fieldsize = ff_file.width * ff_file.height * 8; 
	ff_file.pixels = malloc(px_fieldsize);
	read(file, ff_file.pixels, px_fieldsize);

	close(file);

	return ff_file;
}
