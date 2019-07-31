#include "my_lib.h"
#include <stdlib.h>

int num_in_range(char *s1, char b, char t){
	int bi = b;
	int ti = t;
	int count = 0;
	char *r = s1;
	while(*r != '\0'){
		if(*r >= bi && *r <= ti){
			count += 1;
		}
		r++;
	}
	return count;
}