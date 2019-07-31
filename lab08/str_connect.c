#include "my_lib.h"
#include <stdlib.h>

char *str_connect(char **strs, int n, char c){
	int sizen = 0;
	char * new;
	new = malloc((n*sizeof(char)));
	int j = 0;
	int k = 0;
	//for each word
	for(int i = 0; i < n; i++){
		//for each letter of word
	for( int j = 0; strs[i][j] != '\0'; j++){
		*new = strs[i][j];
		new++;
		sizen++;
		}
		//add c between different words, not after the final word
		if(i != n-1){
		*new = c;
		new++;
		sizen++;
	}
	}
	new++;
	*new= '\0';
	new--;
	///reset new
	while(sizen > 0){
		new--;
		sizen--;
	}
	return new;
}
/*Returns a string consisting of the first n strings in strs with the character c used as a separator. For example, if
strs contains the strings {"Washington", "Adams", "Jefferson"} and c is '+', the function returns the
string "Washington+Adams+Jefferson"*/