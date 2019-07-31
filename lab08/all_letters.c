#include "my_lib.h"
#include <stdlib.h>
int all_letters(char *s){
	char *t=s;

	while(*t != '\0'){
		int val = *t;
		//if val is an upper or lower case letter, move to next position
		if((val >=65 && val <= 90) || (val >= 97 && val <= 122)){
			t++;
		}
		//if val is ever not a letter, return 0
		else{
			return 0;
		}
	}
	return 1;
}