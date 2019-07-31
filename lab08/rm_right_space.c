#include "my_lib.h"
#include <stdlib.h>

void rm_right_space(char *s){
	char *t=s;
	int size = 0;

	//get length of s
	while (*t!='\0'){
		t++;
	}
	size = t-s;

	//move pointer s to the end of the string
	while(size - 1> 0){
		s++;
		size--;
	}

	//while s is whitespace, move s back a position
	while(*s == ' '){
		s--;
	}
	//move forward one position (one position after the last non-white space character in the string and set it to \0
	s++;
	*s = '\0';
}
//removes whitespace characters from the end of s