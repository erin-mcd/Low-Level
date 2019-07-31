#include "my_lib.h"
#include <stdlib.h>

int diff(char *s1, char *s2){
int count = 0;
	while(*s1 != '\0' || *s2 != '\0'){
		//no change needed
		if (*s1 == *s2){
			s1++;
			s2++;
		}
		else{
			if(*s1 == '\0'){
				while(*s2 != '\0'){
					count++;
				}
				return count;
			}
			if(*s2 == '\0'){
				while(*s1 != '\0'){
					count++;
				}
				return count;
			}
			//if they aren't equal but the next character in s1 matched s2(AKA a deletion should happen)
			s1++;
			if(*s1 == *s2){
				count++;
				//move on
				s1++;
				s2++;
			}
			else{
			//deletion test was negative, set back to normal
			s1--;
			//if *s1 is equal to the next *s2, an insertion is necessary
			s2++;
			if(*s1 == *s2){
				count++;
				//move on
				s1++;
				s2++;
			}
			//final option: substituion necessary
			else{
				count++;
				//move on
				s1++;
				s2++;
			}
		}

			
		}
	}
	return count;

}
/*returns the number of positions in which s1 and s2 differ, i.e., it returns the number of changes that would need to
be made in order to transform s1 into s2, where a change could be a character substitution, an insertion, or a
deletion.*/