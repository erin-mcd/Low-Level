#include "my_lib.h"
#include <stdlib.h>

void take_last(char *s, int n){
	char str[n-1];
	char *t = s;
	//move pointer to the end
	while(*t != '\0'){
		t++;
	}
	//move to the last letter
	t--;
	//place letters in str[]
	for(int i = n - 1; i >= 0; i--){
		str[i] = *t;
		t--;
	}
	//move the collected letter in str[] and put them back into s
	for(int i = 0; i < n; i++){
		*s = str[i];
		s++;
	}
	//cut off the string
	*s = '\0';
}
//Modifies s so that it consists of only its last n characters. If n is ≥ the length of s, the original string is unmodified.
//For example if we call take_last("Brubeck" 5), when the function finishes, the original string becomes "ubeck"