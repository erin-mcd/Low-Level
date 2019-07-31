
/*
Objective:
In this assignment, you'll create your own library of string functions. You'll have the opportunity to practice manipulating
strings and managing memory. Additionally, you'll learn the role of header and library files.
You may not call functions in string.h but you can use other code in the Standard C Library.
Task:
Functions to Include in the Library
Implement each of the following functions. Be sure that any string that you create or modify is in fact a string, i.e., an array
of char terminated with the null character, '\0'.
Additionally, you should write a driver which tests each of these functions on real data.*/
#include <stdlib.h>
#include <stdio.h>


int all_letters(char *s);//done
int num_in_range(char *s1, char b, char t);//done
int diff(char *s1, char *s2);//done
void shorten(char *s, int new_len);//done
int len_diff(char *s1, char *s2);//done
void rm_left_space(char *s);//done
void rm_right_space(char *s);//done
void rm_space(char *s);//done
int find(char *h, char *n);//done
char *ptr_to(char *h, char *n);//done
int is_empty(char *s);//done??????????????????????????????????????????
 char * str_zip(char *s1, char *s2);//done
void capitalize(char *s);//done
int strcmp_ign_case(char *s1, char *s2);//done
void take_last(char *s, int n);//done
char * dedup(char *s);//done
char *pad(char *s, int d);//dpne
int ends_with_ignore_case(char *s, char *suff);//done
char *repeat(char *s, int x, char sep);//done
char *replace(char *s, char *pat, char *rep);
char *str_connect(char **strs, int n, char c);//done
void rm_empties(char **words);//some
char **str_chop_all(char *s, char c);//most

int main(){/*

	//test all_letters
	char *str = "heL!lo";
	int all = all_letters(str);
	printf("Does \"%s\" consist of only upper or lower case letters: %d\n",str, all);

	//test num_in_range
	char *strn = "abcdefg";
	char c = 'c';
	char f = 'f';
	int numr = num_in_range(strn, c, f);
	printf("Number of letters between %c and %c in \"%s\": %d\n",c,f,strn, numr);

	//test strr_zip
	char str1[] = "abcdef";
	char str2[] = "zyxwvuts";
	char *newstr= str_zip(str1, str2);
	printf("str_zip: %s\n", newstr); 

	//test find
	char *strf = "hello how are you";
	char *fi = "how";
	int found = find(strf, fi);
	printf("find: %d\n", found);

	char h[] = "helLo How aRe you";
	//*h = toupper(*h);
	capitalize(h);
	printf("h after capitalize: %s\n", h);
	
	int dif = len_diff(strf, str1);
	printf("length difference: %d\n", dif);

	printf("h before shorten: %s\n", h);
	shorten(h, 9);
	printf("h after shorten: %s\n", h);
	//h[5] = '\0';
	char rm[] = "    hello f wefw         ";
	rm_right_space(rm);
	printf("rm after rem_right_space: %s.\n", rm);
	rm_left_space(rm);
	printf("rm after rem_left_space: %s.\n", rm);

	char suff[] = "lo";
	int ign = ends_with_ignore_case(str, suff);
	printf("ends_with_ignore_case: %d", ign);

	//test compareigncase
	char strc2[] = "apple";
	char strc[] = "appasa";
	int compr =  strcmp_ign_case(strc, strc2);
	printf("compr = %d\n", compr);

	char take[] = "asdfghjkl";
	take_last(take, 4);
	printf("take: %s\n", take);
	char *s = "sk";
	char *p = ptr_to(strc, s);
	printf("*p: %c\n", *p);

	char *te = "test";
//	*te = ++*te;
	printf("te: %c\n", *te);

	char *temp;
	//int emp = is_empty(temp);
	//printf("empty: %d\n", emp);

	char rmspace[] = "     werwe wer t re        ";
	rm_space(rmspace);
 		s++;
	printf("rmspace: .%s.\n", rmspace);

	char *hello = "hello";
	char *ded = dedup(hello);
	printf("dedup: %s\n", ded);

	char *padd = "hello";
	char *padded = pad(padd, 4);
	printf("padded: %s\n", padded);

	char *rep = "hello";
	char *repeated = repeat(rep, 4, ',');
	printf("repeat: %s\n", repeated);*/

	char *connect[] = {"Washington", "Adams", "Jefferson"};
	char *connected = str_connect(connect,3,',');
	printf("connected: %s\n", connected);

	char btoken[] = "hello how are you today?";
	char **atoken = str_chop_all(btoken, ' ');

		char *d1 = "hello";
	char *d2 = "asdff";
	int difcount = diff(d1,d2);
	printf("Characters different between %s and %s", d1, d2);

}

int all_letters(char *s){
	char *t=s;

	while(*t != '\0'){
		int val = *t;
		//if val is an upper or lower case letter, move to next position
		if((val >=65 && val <= 90) || (val >= 97 && val <= 122)){
			t++;
		}
		//if val is ever not a letter, return 0
		else{
			return 0;
		}
	}
	return 1;
}
//Returns 1 if all of the characters in the string are either upper- or lower-case letters of the alphabet. It returns 0
//otherwise
int num_in_range(char *s1, char b, char t){
	int bi = b;
	int ti = t;
	int count = 0;
	char *r = s1;
	while(*r != '\0'){
		if(*r >= bi && *r <= ti){
			count += 1;
		}
		r++;
	}
	return count;
}
//returns the number of characters c in s1 such that b<=c<=t
int diff(char *s1, char *s2){
	int count = 0;
	while(*s1 != '\0' || *s2 != '\0'){
		printf("*s1: %c, *s2: %c\n",*s1,*s2);
		if (*s1 == *s2){
			s1++;
			s2++;
		}
		else{
				if(*s1 == '\0' && *s2 == '\0'){
						printf("here5");
					return count;
				
				}
				if(*s1 == '\0'){
				while(*s2 != '\0'){
					printf("here6");
					count++;
				}
				return count;
			}
			if(*s2 == '\0'){
				printf("here4");
				while(*s1 != '\0'){
					count++;
				}
				return count;
			}
			//if they aren't equal but the next character in s1 matched s2(AKA a deletion should happen)
			s1++;
			if(*s1 == *s2){
				printf("here1");
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
				printf("here2");
				count++;
				//move on
				s1++;
				s2++;
			}
			//final option: substituion necessary
			else{
				printf("here3");
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
void shorten(char *s, int new_len){
	char *t=s;
	int size = 0;
	while (*t!='\0'){
		t++;
	}
	size = t-s;
	if(new_len < size){
		s[new_len] = '\0';
	}
}

//Shortens the string s to new_len. If the original length of s is less than or equal to new_len, s is unchanged
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
//Returns the length of s1 - the length of s2
void rm_left_space(char *s){//not finished
	char t[100];
	int i = 0;
	int count = 0;
	//while s is still at the white space on the left, continue moving s to the right and increasee count
	while(*s == ' '){
		s++;
		count++;
	}
	//at the first non0whitespace char, set t[i] to *s (the rest of the string)
	while(*s != '\0'){
		t[i] = *s;
		s++;
		i++;
	}
	count += i;
	//bring s back to the beginning
	while(count > 0){
		s--;
		count--;
	}
	//overwrite the beggining of s with the non-white space portion
	for(int j = 0; j < i; j++){
		*s = t[j];
		s++;
	}
	//move s to the next position after where the non-white space portion of the string was placed and set it to \0
	s++;
	*s = '\0';

}
//removes whitespace characters from the beginning of s

void rm_right_space(char *s){
	char *t=s;
	int size = 0;

	//get length of s
	while (*t!='\0'){
		t++;
	}
	size = t-s;

	//move pointer s to the end of the string
	while(size - 1> 0){
		s++;
		size--;
	}

	//while s is whitespace, move s back a position
	while(*s == ' '){
		s--;
	}
	//move forward one position (one position after the last non-white space character in the string and set it to \0
	s++;
	*s = '\0';
}
//removes whitespace characters from the end of s
void rm_space(char *s){
char t[100];
	int i = 0;
	int count = 0;
	//while s is still at the white space on the left, continue moving s to the right and increasee count
	while(*s == ' '){
		s++;
		count++;
	}
	//at the first non hitespace char, set t[i] to *s (the rest of the string)
	while(*s != '\0'){
		t[i] = *s;
		s++;
		i++;
	}
	count += i;
	//bring s back to the beginning
	while(count > 0){
		s--;
		count--;
	}
	//overwrite the beggining of s with the non-white space portion
	for(int j = 0; j < i; j++){
		*s = t[j];
		s++;
	}
	//move s to the next position after where the non-white space portion of the string was placed and set it to \0
	s++;
	*s = '\0';
	printf("s: %s\n", s);
	s--;
	//while s is whitespace, move s back a position
	while(*s == ' '){
		s--;
	}
	//move forward one position (one position after the last non-white space character in the string and set it to \0
	s++;
	*s = '\0';

}
//removes whitespace characters from the beginning and the ending s

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
char *ptr_to(char *h, char *n){
	
	char *r = malloc(sizeof(*r));
	while(*h != '\0'){
		if(*h == *n){
			r = n;
			return r;
		}
		h++;
	}
	return NULL;
}
//returns a pointer to the first occurrence of n in the string h or NULL if it isn't found
int is_empty(char *s){
	int t = *s;
	while( *s != '\0'){
		t = *s;
		if((t == 0 || t == 32)){
			s++;
		}
		else{
			return 0;
		}
	}
	return 1;
}
	
//returns 1 if s is NULL, consists of only the null character ('') or only whitespace. returns 0 otherwise.
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
void capitalize(char *s){
	int isSpace = 1;
	printf("%c", *s);
	int w = *s;

	while(*s != '\0'){
		w = *s;
		if(*s == ' '){
			//*s is a space
			isSpace = 1;
		}
		else{
			if(isSpace == 1){
				//isSpace  == 1 and *s is lowercase
				if( w  >= 97 && w <= 122){ 
					*s = w - 32;
				}
			}
			else{
				//isSpace == 0 and *s is uppercase
				if(w  >= 65 && w <= 90){
					*s = w + 32;
				}
			}
				//reset
				isSpace = 0;
			}
		s++;
	}

}
//Changes s so that the first letter of every word is in upper case and each additional letter is in lower case.
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
char * pad(char *s, int d){
	char *t=s;
	int size = 0;
	int numspaces = 0;
	int count = 0;

	while (*t!= '\0'){
	 t++;
	}
	 size = t-s;
	 char *new;
	 //allocated space with sufficient space for the size to be a multiple of d
	 new = calloc(d*size + 1,sizeof(char));
	 numspaces = d*size - size;

	 //if size is already multiple of d
	 if(size%d == 0){
	 	return s;
	 }
	 else{
	 	//fill in new with all characters of s
	 	while(*s != '\0'){
	 		*new = *s;
	 		count++;
	 		new++;
	 		s++;
	 	}
	 	//then after the original s, fill in the rest with spaces
	 	while(numspaces > 0){
	 		*new = ' ';
	 		numspaces--;
	 		new++;
	 		count++;
	 	}
	 	*new = '\0';
	 	//reset new
	 	while(count > 0){
	 		new--;
	 		count--;
	 	}
	 	
	 }
	return new;
}
/*returns a new string consisting of all of the letters of s, but padded with spaces at the end so that the total length
of the returned string is an even multiple of d. If the length of s is already an even multiple of d, the function
returns a copy of s. The function returns NULL on failure or if s is NULL. Otherwise, it returns the new string. It is
up to the caller to free any memory allocated by the function.*/
int ends_with_ignore_case(char *s, char *suff){
	char *t=suff;
	int size = 0;
	
	while (*s!='\0'){
		//ignore case
		if(*s  >= 65 && *s <= 90){
			*s = *s + 32;
		}
		s++;
	}

	while (*t!='\0'){
		//ignore case
		if(*t  >= 65 && *t <= 90){
			*t = *t + 32;
		}
		t++;
	}
	size = t-suff;
	//set t and s back to the last letter
	s--;
	t--;

	//starting at the last letter in s, check is the chars in s match the cahrs in t (checking from right to left)
	for(int i = 0; i < size; i++){
		printf("*s  %c *t  %c\n", *s, *t );
		if(*s != *t){
			return 0;
		}
		s--;
		t--;
	}
	return 1;

}
//returns 1 if suff is a suffix of s ignoring case or 0 otherwise.
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
char *replace(char *s, char *pat, char *rep){
	char *t=rep;
	int size = 0;
	char *new;
	int repcount = 0;
	

	while (*t!= '\0'){
	 t++;
	}
	size = t-s;
 	new = malloc(sizeof(char)*size);

	while(*s != '0'){
		if(*s == *pat){
			repcount += 1;
			new = realloc(new, sizeof(char)*size*repcount);
			for(int i = 0; i < size; i++){

			}
	}
}
}
/*Returns a copy of the string s, but with each instance of pat replaced with rep, note that len(pat) can be less
than, greater than, or equal to len(rep). The function allocates memory for the resulting string, and it is up to
the caller to free it. For example, if we call replace("NBA X", "X", "rocks"), what is returned is the new
string NBA rocks (but remember, pat could be longer than an individual character and could occur multiple
times).*/
char *str_connect(char **strs, int n, char c){
	int sizen = 0;
	char * new;
	new = malloc((n*sizeof(char)));
	int j = 0;
	int k = 0;
	for(int i = 0; i < n; i++){
	for( int j = 0; strs[i][j] != '\0'; j++){
		*new = strs[i][j];
		new++;
		sizen++;
		}
		if(i != n-1){
		*new = c;
		new++;
		sizen++;
	}
	}
	while(sizen > 0){
		new--;
		sizen--;
	}
	return new;
}
/*Returns a string consisting of the first n strings in strs with the character c used as a separator. For example, if
strs contains the strings {"Washington", "Adams", "Jefferson"} and c is '+', the function returns the
string "Washington+Adams+Jefferson"*/
void rm_empties(char **words){/*

if(**words == '\0'){
      for (c = position - 1; c < n - 1; c++){
         array[c] = array[c+1];
      }
 
      printf("Resultant array:\n");
 
      for (c = 0; c < n - 1; c++){
         printf("%d\n", array[c]);
      }
   }*/
}
//words is an array of string terminated with a NULL pointer. The function removes any empty strings (i.e., strings
//of length 0) from the array.
char **str_chop_all(char *s, char c){
	static char tokens[100][100];
	int i = 0;
	int j = 0;
	int k = 0;
	int sincedel = 0;
	while(s[k] != '\0'){
	//	printf("s[k] = %c", s[k]);
		//c[k] is not c
		if(s[k] != c){
			tokens[i][j] = c;
//			printf("tokens[%d][%d]: %c\n", i,j, tokens[i][j]);
			k++;
			j++;
			sincedel += 1;
		}
		//s[k] is c
		else{
		//	printf("space\n");
			k++;
			j = 0;
			i++;
		}
	}
	//return tokens;
}
//Returns an array of string consisting of the characters in s split into tokens based on the delimeter c, followed by
//a NULL pointer. For example, if s is "I am ready for a nice vacation" and c is ' ', it returns {"I", "am",
//"ready", "for", "a", "nice", "vacation", NULL}
//Pointer vs Array Notation
/*Though it's not a formal requirement, it is suggested that you try to do some of these using pointer notation instead of
array notation.
For example, we could write a string length function as:
int strlen(char s[])
{
 int i=0;
 while (s[i]!='\0')
 i++;
 return i;
}
We could also write:
int strlen(char *s)
{
 char *t=s;
 while (*t!='\0')
 t++;
 return t-s;
}
*/