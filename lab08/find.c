#include "my_lib.h"
#include <stdlib.h>

int find(char *h, char *n){
	//hhow didn't work
	int count = 0;
	int tempcount = 0;
	char first = *n;
while (*h != '\0'){
//	printf("h: %c\n", *h);
//	printf("n: %c\n", *n);
if(*h != *n){
	h++;
	count += 1;
//	printf("count: %d\n", count);
	count += tempcount;
//	printf("count + tempcount: %d\n", count);
	tempcount = 0;
}
else{
	while(*n == *h){
		h++;
		n++;
		tempcount += 1;
		//printf("tempcount: %d\n", tempcount);
	}
	if(*n == '\0'){
		return count;
	}
	for( int i = 0; i < tempcount; i++){
		n--;
	}

}

}
return -1;
}
//returns the index of the first occurrence of n in the string h or -1 if it isn't found.