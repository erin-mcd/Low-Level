#include "my_lib.h"
#include <stdlib.h>

int len_diff(char *s1, char *s2){
	char *t=s1;
	int size1 = 0;
	uint result = 0;

//get length os s1
 while (*t!='\0'){
 t++;
 }
 size1 =  t-s1;
 char *u=s2;

 int size2 = 0;
 //get length of s2
 while (*u!='\0'){
 u++;
 }
 size2 =  u-s2;
 //get difference in lengths
 result = size2 - size1;//MAKE UNSIGNED
 return result;
}