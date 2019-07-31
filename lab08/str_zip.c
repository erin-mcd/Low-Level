#include "my_lib.h"
#include <stdlib.h>

char *str_zip(char *s1, char *s2){
static char c[100];
int i = 0;
		while( *s1 != '\0' || *s2!= '\0'){
			if(*s1 == '\0'){
				c[i] = *s2;
				i++;
				s2++;
			}
			else if(*s2 == '\0'){
			c[i] = *s1;
			i++;
			s1++;

			}
			else{
				c[i] = *s1;
				i++;
				c[i] = *s2;
				i++;
				s2++;
				s1++;
			}

		}
		return c;
	}

//Returns a new string consisting of all of the characters of s1 and s2 interleaved with each other. For example, if
//s1 is "Spongebob" and s2 is "Patrick", the function returns the string "SPpaotnrgiecbkob"