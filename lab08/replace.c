#include "my_lib.h"
#include <stdlib.h>

char *replace(char *s, char *pat, char *rep){

}
/*Returns a copy of the string s, but with each instance of pat replaced with rep, note that len(pat) can be less
than, greater than, or equal to len(rep). The function allocates memory for the resulting string, and it is up to
the caller to free it. For example, if we call replace("NBA X", "X", "rocks"), what is returned is the new
string NBA rocks (but remember, pat could be longer than an individual character and could occur multiple
times).*/