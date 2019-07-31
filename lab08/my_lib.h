#ifndef MY_LIB_H_
#define MY_LIB_H_

int all_letters(char *s);//done
int num_in_range(char *s1, char b, char t);//done
int diff(char *s1, char *s2);
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
char *str_connect(char **strs, int n, char c);
void rm_empties(char **words);
char **str_chop_all(char *s, char c);

#endif