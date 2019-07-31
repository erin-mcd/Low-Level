#include "my_lib.h"
#include <stdlib.h>

void shorten(char *s, int new_len){
	char *t=s;
	int size = 0;
	while (*t!='\0'){
		t++;
	}
	size = t-s;
	if(new_len < size){
		s[new_len] = '\0';
	}
}
