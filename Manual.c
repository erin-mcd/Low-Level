/*
 * Name:	Erin McDonald
 * Section:	003
 * Date:	03/20/2019 	
 * Lab:  	CIS2107_Lab07_Manual 
 * Goal: 	To design and implement functions to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test4", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {                //MAKE BETTER
  char  a[100];
  //put string into the array
  for(size_t i = 0; *s != '\0'; i++){
    a[i] = *s;
    s++;
  }
  for(size_t i = 0;a[i] != '\0'; i++){
    printf("%c", toupper(a[i]));
  }
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    int total = atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
    return total;

}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
 float total = atof(s1) + atof(s2) + atof(s3) + atof(s4);
 return total;
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
  int compare = strcmp(s1, s2);
  if(compare < 0){
    printf("\n\nThe first string is less than the second.");
  }
  else if(compare == 0){
    printf("\n\nThe two strings are equal.");
  }
  else{
    printf("\n\nThe first string is greater than the second.");
  }

}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
  int compare = strncmp(s1, s2, n);
  if(compare < 0){
    printf("\n\nThe first string is less than the second up to %d.", n);
  }
  else if(compare == 0){
    printf("\n\nThe two strings are equal up to %d.", n);
  }
  else{
    printf("\n\nThe first string is greater than the second up to %d.", n);
  }
}

//6.(Random Sentences) 
void randomize(void) {
  int count = 0;
  printf("\n");
  while(count < 20){
  int a = rand() % 5;
  int b = rand() % 5;
  int c = rand() % 5;
  int d = rand() % 5;
  int e = rand() % 5;
  int f = rand() % 5;
  char *article[] = {"the", "a", "one", "some", "any"};
  char *noun[] = {"boy", "girl", "dog", "town", "car"};
  char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
  char *prep[] = {"to", "from", "over", "under", "on"};
  char *sentence[]= {article[a], noun[b], verb[c], prep[d], article[e], noun[f]};
  printf("\n");
  for(int i = 0; i < 6; i++){
    if(i == 0){
      printf("%c", toupper(*sentence[0]));
      sentence[0]++;
      printf("%s ", sentence[0]);
    }
    else if(i == 5){
      printf("%s.", sentence[i]);
    }
    else{
      printf("%s ", sentence[i]);
    }
  }
  count++;
}
}
//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
  char *ptr;
 int count = 0;
  char * tokens[2];
  size_t n = 0;

for (char * p = strtok(num, "-() "); p; p = strtok(NULL, "-() "))
{
    tokens[n++] = p;
    count++;
}
 char *new = strcat(tokens[1], tokens[2]);
 long seven = strtol(new, &ptr, 10);
 int area = atoi(tokens[0]);
 printf("\n\narea code: %d   phone-number: %ld ", area, seven);
 

}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
  int count = 0;
  char * tokens[50];
  size_t n = 0;

for (char * p = strtok(text, " "); p; p = strtok(NULL, " "))
{
    if (n >= 50)
    {
        // maximum number of storable tokens exceeded
        break;
    }
    tokens[n++] = p;
    count++;
}
 printf("\n\nReversed sentence: ");
  for(size_t i = n; i > 0; i--){
    printf("%s", tokens[i-1]);
    printf(" ");
  }
  printf("\n\n");
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
 int count = 0;
  int length = strlen(sub);
  while(strstr(line,sub) != NULL){
    line = strstr(line,sub);
    for(int i = 0; i < length; i++){
      line++;
    }
    count++;
  }
  return count;
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;
  while(strchr(line,c) != NULL){
    line = strchr(line, c);
    line++;
    count++;
  }
  return count;
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
  printf("\nCounting the letters in %s:", string);
  *string = tolower(*string);
  int count[26];
  printf("\n");
  for(int i = 0; i < 26; i++){
    count[i] = 0;
    char *p = string;
   while(strchr(p, 'a' + i) != NULL){
     count[i] += 1;
     p = strchr(p, 'a' + i);
     p++;
    
  }
  }

  for (int i = 0; i < 26; i++){
    char out = 'a' + i;
    printf("%c: %d ", out, count[i]);
}
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
  int count = 0;
   for (char * p = strtok(string, " "); p; p = strtok(NULL, " ")){
    count++;
   }
   return count;  
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {
  printf("\n\nWords that start with the letter B: ");
  for(int i =0; i < 5; i++){
    if (*string[0] == 'b' || *string[0] == 'B'){
      printf("%s ", *string);
      string++;
    }
    else{
      string++;
    }
    }
}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {
   printf("\n\nWords that end with the letters ed: ");
   for(int i =0; i < 5; i++){
    int strsize = strlen(string[i]);
   
    char *p = string[i];
	 
       for(int j = 0 ; j < strsize-2; j ++){
         *p++;
	 
       }
       if (*p == 'e'){
	 *p++;
	 if(*p == 'd'){
	   printf("%s ", string[i]);
	 }   
       }	     
   }
   printf("\n");
}
