#include "my_lib.h"
#include <stdlib.h>

int strcmp_ign_case(char *s1, char *s2){
	while(*s1 != '\0' || *s2 != '\0'){
		//ignore case
		if(*s1  >= 65 && *s1 <= 90){
			*s1 = *s1 + 32;
		}
		if(*s2  >= 65 && *s2 <= 90){
			*s2 = *s2 + 32;
		}

		//when string are the same, but then one ends before the other, the shorter one comes first
		if(*s2 == '\0'){
			return 1;
		}
		if(*s1 == '\0'){
			return -1;
		}

		//if they are the same char, continue
		if(*s1 == *s2){
			s1++;
			s2++;
		}
		if(*s1 > *s2){
			return 1;
		}


		if(*s1 > *s2){
			return 1;
		}
		if(*s1 < *s2){
			return -1;
		}
		
	}
	return 0;
}
//Compares s1 and s2 ignoring case. Returns a positive number if s1 would appear after s2 in the dictionary, a
//negative number if it would appear before s2, or 0 if the two are equal.