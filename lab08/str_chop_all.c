#include "my_lib.h"
#include <stdlib.h>

char **str_chop_all(char *s, char c){
	static char tokens[100][100];
	int i = 0;
	int j = 0;
	int k = 0;
	int sincedel = 0;
	while(s[k] != '\0'){
		//c[k] is not c
		if(s[k] != c){
			tokens[i][j] = c;
			k++;
			j++;
			sincedel += 1;
		}
		//s[k] is c
		else{
			k++;
			j = 0;
			i++;
		}
	}
//	return tokens;
}
//Returns an array of string consisting of the characters in s split into tokens based on the delimeter c, followed by
//a NULL pointer. For example, if s is "I am ready for a nice vacation" and c is ' ', it returns {"I", "am",
//"ready", "for", "a", "nice", "vacation", NULL}