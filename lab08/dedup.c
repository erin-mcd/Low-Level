#include "my_lib.h"
#include <stdlib.h>

char * dedup(char *s){
	int first = 1;
	char *compare = s;
	int cp = 0;
	int sp = 0;
	char *new = malloc(sizeof(char)*4);
	int count = 0;

	while(*s != '\0'){
		if(first == 1){
			*new = *s;
			new++;
			count++;
			s++;
			sp++;
			first = 0;
			continue;
		}

		while(cp != sp){
			//letter already present in new
			if(*compare == *s){
				s++;
				sp++;
				break;
			}
			else{
				cp++;
				compare++;
			}
			
		}
		//compared all letters before *s and didn't find a match
		if(cp == sp){
			*new = *s;
			new++;
			sp++;
			s++;
			count +=1;
			
		}
		//set compare and cp back to the start
		while(cp > 0){
					cp--;
					compare--;
				}
	}
	//set new back to the beginning.
	while(count > 0){
		new--;
		count--;
	}
	return new;
}
//returns a new string based on s, but without any duplicate characters. For example, if s is the string, "There's
//always money in the banana stand.", the function returns the string "Ther's alwymonitbd.". It is up
//to the caller to free the memory allocated by the function.