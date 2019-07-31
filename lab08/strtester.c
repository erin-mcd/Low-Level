#include "my_lib.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

	//test all_letters
	char *str = "heL!lo";
	int all = all_letters(str);
	printf("Does \"%s\" consist of only upper or lower case letters: %d\n\n",str, all);

	//test num_in_range
	char *strn = "abcdefg";
	char c = 'c';
	char f = 'f';
	int numr = num_in_range(strn, c, f);
	printf("Number of letters between %c and %c in \"%s\": %d\n\n",c,f,strn, numr);

	//test strr_zip
	char str1[] = "abcdef";
	char str2[] = "zyxwvuts";
	char *newstr= str_zip(str1, str2);
	printf("str1[] = %s, str2[] = %s, after str_zip(str1,str2): %s\n\n",str1,str2, newstr); 

	//test find
	char *strf = "hello how are you";
	char *fi = "how";
	int found = find(strf, fi);
	printf("index of \"%s\" in \"%s\" find: %d\n\n",fi, strf, found);

	char h[] = "helLo How aRe you";
	printf("Before capitalize: \"%s\"\n", h);
	//*h = toupper(*h);
	capitalize(h);
	printf("After capitalize: \"%s\"\n\n", h);
	
	int dif = len_diff(strf, str1);
	printf("length difference between \"%s\" and \"%s\": %d\n\n",strf, str1, dif);

	printf("Before shorten: \"%s\"\n", h);
	shorten(h, 9);
	printf("After shorten: \"%s\"\n\n", h);
	//h[5] = '\0';
	char rm[] = "    hello f wefw         ";
	printf("Original: \"%s\"\n", rm);
	rm_right_space(rm);
	printf("After rem_right_space: \"%s\"\n", rm);
	rm_left_space(rm);
	printf("After rem_left_space: \"%s\"\n\n", rm);

	char suff[] = "lo";
	char suffstr[] = "hello";
	int ign = ends_with_ignore_case(suffstr, suff);
	printf("Does \"%s\" end with \"%s\"?: %d\n\n",suffstr, suff, ign);

	//test compareigncase
	char strc2[] = "apple";
	char strc[] = "appasa";
	int compr =  strcmp_ign_case(strc, strc2);
	printf("Compare \"%s\" with \"%s\" = %d\n\n",strc2, strc, compr);

	//test take
	char take[] = "asdfghjkl";
	int in = 4;
	printf("Taking the last %d from \"%s\": ",in,take);
	take_last(take, in);
 	printf("\"%s\"\n\n", take);

 	//test ptr_to
 	char *sk= "ski";
	char *s = "sk";
	char *p = ptr_to(sk, s);
	printf("Pointer to %s: %s\n\n",s, p);

	char *temp;
	//int emp = is_empty(temp);
	//printf("empty: %d\n", emp);

	char rmspace[] = "     hello        ";
	printf("Before rm_space: \"%s\"\n", rmspace);
	rm_space(rmspace);
	printf("After rmspace: \"%s\"\n\n", rmspace);

	char *hello = "hello";
	char *ded = dedup(hello);
	printf("Original: \"%s\", After dedup: \"%s\"\n\n",hello, ded);

	char *padd = "hello";
	char *padded = pad(padd, 4);
	printf("Original: \"%s\", padded(original, 4): \"%s\"\n\n",padd, padded);

	char *rep = "hello";
	char *repeated = repeat(rep, 4, ',');
	printf("Original: \"%s\", After repeat: \"%s\"\n\n",rep, repeated);

	char *connect[] = {"Washington", "Adams", "Jefferson"};
	char *connected = str_connect(connect,3,',');
	printf("connected: %s\n", connected);

	char *d1 = "hello";
	char *d2 = "asdff";
	int difcount = diff(d1,d2);
	printf("Characters different between %s and %s", d1, d2);

	//can't get str_chop_all to return
	//rm_empties
	//replace incomplete
}
