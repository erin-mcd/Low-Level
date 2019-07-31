#include "my_lib.h"
#include <stdlib.h>

void capitalize(char *s){
	int isSpace = 1;
	int w = *s;

	while(*s != '\0'){
		w = *s;
		if(*s == ' '){
			//*s is a space
			isSpace = 1;
		}
		else{
			if(isSpace == 1){
				//isSpace  == 1 and *s is lowercase
				if( w  >= 97 && w <= 122){ 
					*s = w - 32;
				}
			}
			else{
				//isSpace == 0 and *s is uppercase
				if(w  >= 65 && w <= 90){
					*s = w + 32;
				}
			}
				//reset
				isSpace = 0;
			}
		s++;
	}
}
//Changes s so that the first letter of every word is in upper case and each additional letter is in lower case.