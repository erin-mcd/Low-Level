#include "my_lib.h"
#include <stdlib.h>

char *repeat(char *s, int x, char sep){
	char *t=s;
	int size = 0;
	char *new;
	//allocate enough memory for s to be repeated x times, plus insertions of sep
	new = malloc(sizeof(char)*size*x+x);
	

	while (*t!= '\0'){
	 t++;
	}
	size = t-s;
	int count = size*x+x;

	//for the amout of times s should repeat
	for(int i = 1; i < x+1; i++){
		char *move = s;

		//place s into new
		while(*move != '\0'){
			*new = *move;
			new++;
			move++;
		}
		//if not the last iteration, place sep into new
		if(i != x){
		*new = sep;
		new++;
		}
	}

	new++;
	*new = '\0';
	//reset new
	while(count > 0){
		new--;
		count--;
	}

	return new;
}
/*Returns a new string consisting of the characters in s repeated x times, with the character sep in between. For
example, if s is the string all right, x is 3, and sep is , the function returns the new string all right,all
right,all right. If s is NULL, the function returns NULL. It is up to the caller to free any memory allocated by
the function.*/