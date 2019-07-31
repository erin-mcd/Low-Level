#include "my_lib.h"
#include <stdlib.h>

void rm_left_space(char *s){//not finished
	char t[100];
	int i = 0;
	int count = 0;
	//while s is still at the white space on the left, continue moving s to the right and increasee count
	while(*s == ' '){
		s++;
		count++;
	}
	//at the first non0whitespace char, set t[i] to *s (the rest of the string)
	while(*s != '\0'){
		t[i] = *s;
		s++;
		i++;
	}
	count += i;
	//bring s back to the beginning
	while(count > 0){
		s--;
		count--;
	}
	//overwrite the beggining of s with the non-white space portion
	for(int j = 0; j < i; j++){
		*s = t[j];
		s++;
	}
	//move s to the next position after where the non-white space portion of the string was placed and set it to \0
	s++;
	*s = '\0';

}
//removes whitespace characters from the beginning of s