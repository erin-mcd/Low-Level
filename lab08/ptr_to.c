#include "my_lib.h"
#include <stdlib.h>

char *ptr_to(char *h, char *n){
	
	char *r = malloc(sizeof(*r));
	while(*h != '\0'){
		if(*h == *n){
			r = n;
			return r;
		}
		h++;
	}
	return NULL;
}
//returns a pointer to the first occurrence of n in the string h or NULL if it isn't found