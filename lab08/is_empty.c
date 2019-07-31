#include "my_lib.h"
#include <stdlib.h>

int is_empty(char *s){
	int t = *s;
	while( *s != '\0'){
		t = *s;
		if((t == 0 || t == 32)){
			s++;
		}
		else{
			return 0;
		}
	}
	return 1;
}
	
//returns 1 if s is NULL, consists of only the null character ('') or only whitespace. returns 0 otherwise.