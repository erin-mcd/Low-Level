#include "my_lib.h"
#include <stdlib.h>

int ends_with_ignore_case(char *s, char *suff){
	char *t=suff;
	int size = 0;
	
	while (*s!='\0'){
		//ignore case
		if(*s  >= 65 && *s <= 90){
			*s = *s + 32;
		}
		s++;
	}

	while (*t!='\0'){
		//ignore case
		if(*t  >= 65 && *t <= 90){
			*t = *t + 32;
		}
		t++;
	}
	size = t-suff;
	//set t and s back to the last letter
	s--;
	t--;

	//starting at the last letter in s, check is the chars in s match the cahrs in t (checking from right to left)
	for(int i = 0; i < size; i++){
		if(*s != *t){
			return 0;
		}
		s--;
		t--;
	}
	return 1;

}
//returns 1 if suff is a suffix of s ignoring case or 0 otherwise.