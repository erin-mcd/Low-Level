#include "my_lib.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

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
//	rm_right_space(rm);
//	printf("rm after rem_right_space: %s.\n", rm);
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
	printf("repeat: %s\n", repeated);

	//char *connect[] = {"Washington", "Adams", "Jefferson"};
	//char *connected = str_connect(connect,2,',');
	//printf("connected: %s\n", connected);
}
