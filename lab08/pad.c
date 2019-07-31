#include "my_lib.h"
#include <stdlib.h>

char * pad(char *s, int d){
	char *t=s;
	int size = 0;
	int numspaces = 0;
	int count = 0;

	while (*t!= '\0'){
	 t++;
	}
	 size = t-s;
	 char *new;
	 //allocated space with sufficient space for the size to be a multiple of d
	 new = calloc(d*size + 1,sizeof(char));
	 numspaces = d*size - size;

	 //if size is already multiple of d
	 if(size%d == 0){
	 	return s;
	 }
	 else{
	 	//fill in new with all characters of s
	 	while(*s != '\0'){
	 		*new = *s;
	 		count++;
	 		new++;
	 		s++;
	 	}
	 	//then after the original s, fill in the rest with spaces
	 	while(numspaces > 0){
	 		*new = ' ';
	 		numspaces--;
	 		new++;
	 		count++;
	 	}
	 	*new = '\0';
	 	//reset new
	 	while(count > 0){
	 		new--;
	 		count--;
	 	}
	 	
	 }
	return new;
}
/*returns a new string consisting of all of the letters of s, but padded with spaces at the end so that the total length
of the returned string is an even multiple of d. If the length of s is already an even multiple of d, the function
returns a copy of s. The function returns NULL on failure or if s is NULL. Otherwise, it returns the new string. It is
up to the caller to free any memory allocated by the function.*/