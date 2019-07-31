/*
Erin McDonald
4/28/2019
CIS 2017
Lab 10
Attached is an unfinished main.cfor a project called WeatherLogs.Complete all of the unfinished functions and rewrite the ones started for you so that each computes the correct result using only the "bitwise" operators (&, |, ^, <<, >>, ~) along with(!, =, ==, !=, && and ||)
*/


#include <stdio.h>
#include <stdint.h>

/* weatherlog_t is a "weather sensor log type"
 which is really defined as a 64-bit unsigned
 integer.  See below. */
typedef uint64_t weatherlog_t;

unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);

void print_half_nybbles(unsigned int);
unsigned int reverse_half_nybbles(unsigned int);

int has_odd(unsigned int);
unsigned int make_odd(unsigned int);

int is_negative(int);

weatherlog_t pack_log_entry(unsigned int, unsigned int, unsigned int,
                            unsigned int,
                            int, int,
                            unsigned int, unsigned int);

unsigned int get_year(weatherlog_t entry);
unsigned int get_month(weatherlog_t entry);
unsigned int get_day(weatherlog_t entry);
unsigned int get_zip(weatherlog_t entry);
unsigned int get_high(weatherlog_t entry);
unsigned int get_low(weatherlog_t entry);
unsigned int get_precip(weatherlog_t entry);
unsigned int get_wind(weatherlog_t entry);

int main(int argc, char **argv) {
    unsigned int i, j;
    int x, y;
    unsigned int year, month, day,
    zip, high_temp, low_temp, precip, avg_wind_speed;
    weatherlog_t log_entry;

    
    printf("Enter an integer: ");
    scanf("%u", &i);
    printf("Enter another integer: ");
    scanf("%u", &j);
    printf("One more integer, please: ");
    scanf("%d", &x);
    printf("Please enter a positive integer: ");
    scanf("%d", &y);
    
    printf("i + j = %u\n", add(i,j));
    printf("i - j = %u\n", sub(i,j));
    printf("i * j = %u\n", mul(i,j));
    
    if (is_negative(x))
       printf("%d is negative\n", x);
   else
        printf("%d is non-negative\n", x);
    
    if (has_odd(y)) {
        printf("%x has an odd number of bits in its binary representation\n", y);
    }
    else {
        printf("%x has an even number of bits in its binary representation\n", y);
        printf("but %x has an odd number of bits in its binary representation\n", make_odd(y));
    }
 
    printf("The half-nybbles of %d (in hex 0x%x) are:", x, x);
    print_half_nybbles(x);
      
    printf("%x with reversed half-nybbles is: ", x);
    reverse_half_nybbles(x);
    
    printf("Enter a year: ");
    scanf("%u", &year);
    
    printf("Enter a month as an integer (1-12): ");
    scanf("%u", &month);
    
    printf("Enter a day as an integer (1-31): ");
    scanf("%u", &day);
    
    printf("Enter a zip code as an integer (0-99999): ");
    scanf("%u", &zip);
    
    printf("Enter a temperature as an integer: ");
    scanf("%u", &high_temp);
    
    printf("Enter another temperature as an integer: ");
    scanf("%u", &low_temp);
    
    
    printf("Enter rainfall amount as an integer (mm): ");
    scanf("%u", &precip);
    
    printf("Enter a as an integer (km/hr): ");
    scanf("%u", &avg_wind_speed);
    
    
    log_entry=pack_log_entry(year, month, day, zip, high_temp, low_temp,
                             precip, avg_wind_speed);
    printf("You entered: %u/%u/%u for zip %5d: high %d F, low %d F, precip %d mm, wind speed %d km/hr\n",
           get_day(log_entry), get_month(log_entry), get_year(log_entry),
           get_zip(log_entry), get_high(log_entry), get_low(log_entry),
           get_precip(log_entry), get_wind(log_entry));
    return 0;
}

unsigned int add(unsigned int i, unsigned int j) {
    /* can be done in a total of 7 lines, including one to declare an unsigned int, */
    /* two for a while loop, and one for the return
     You're not required to do it in 7 lines though . */

    while (j != 0) { 
        //keeps track of where i and j are the same
        unsigned int carry = i & j;  
        //i = i XOR j 
        i = i ^ j;  
        //shift
        j = carry << 1; 
    } 
    return i; 
}

unsigned int sub(unsigned int i, unsigned int j) {
    /* Similar 7 lines, although there is a shorter way */
    while (j != 0) 
    { 
        //keeps track of where ~i and j are the same 
        unsigned int borrow = (~i) & j; 
  
        //i = i XOR j
        i = i ^ j; 
  
        //shift
        j = borrow << 1; 
    } 
    return i; 
}

unsigned int mul(unsigned int i, unsigned int j) {
    /* can be done in a total of 8 lines including one to declare unsigned ints */
    /* two for a for loop, and one for the return */
    unsigned int result = 0;  // initialize result 
  
    // while j isn't 1
    while (j > 0) 
    { 
         // if j number is odd, add i to result 
         if (j & 1) 
             result = result + i; 
  
         // 2*i and (1/2)j 
         i = i << 1; 
         j = j >> 1; 
     } 
     return result; 
}

/* prints the half-nybbles (i.e. 2 bit values) of x,
 one half-nybble at a time */
unsigned int reverse_half_nybbles(unsigned int x) {
      int count = 0;
    while (x) {
        //separate into half nybbles
        if(count == 2){
            printf(" ");
            count = 0;
        }
        //print values
        if (x & 1){
            printf("1");
        }
        else{
            printf("0");
        }
        //shift
        x = x >> 1;
        count = add(count,1);
    }
    printf("\n");
    return 0u;
}

/* returns the reverse of the half-nybbles of i */
void print_half_nybbles(unsigned int i) {
  int size = 0;
    int get = i;

    //get size necessary to store the int
    while(get){
        size = add(size,1);
        get = get >> 1;
    }

    int ar[size];
    int count = 0;
    //places binary values into an array, but in the reverse order they appear in
    for(int j = 0; j < size;j = add(j,1)){
        if(i & 1){
          ar[size-j-1] = 1;
         }
         else{
            ar[size-j-1] = 0;
         }
         //shift
        i = i >> 1;
    }

    for(int j = 0; j < size; j = add(j,1)){
        //half-nybbles: print space after two numbers have been printed
         if(count == 2){
            printf(" ");
            count = 0;
        }
        printf("%d", ar[j]);
        count = add(count, 1);
    }
     printf("\n");
}


/* returns 1 if x < 0
 returns 0 otherwise
 
 Do not use the <, > operators. */
int is_negative(int x) {
     int get = x;
     int size = 0;
    //get size necessary to store the int
    while(get != -1 && get !=0){
       // print_half_nybbles(get);
        size = add(size,1);
        get = get >> 1;
    }
 
    x = x >> size;
    if(x&1){
        return 1;
    }
    return 0;
}

/* returns 1 if x's binary representation
 has an odd number of 1s or 0 otherwise */
int has_odd(unsigned int x) {
    int odd = 0;
    while(x){
        if(x & 1 ){
            //if it has seen an even amount of 1s before this
            if(odd == 0){
                odd = 1;
            }
            //has seen an odd amount of 1s before this
            else{
                odd = 0;
            }
            x = x >> 1;
        }
        else{
            x = x >> 1;
        }

    }
    return odd;
}

/* If x's binary representation contains an odd number of 1s, x is
 returned. Otherwise, it returns a copy of x, but with its most significant
 bit modified so that there is an odd number of 1s. */
unsigned int make_odd(unsigned int x) {
    int size = 0;
    int get = x;

    //get size necessary to store the int
    while(get){
        size = add(size,1);
        get = get >> 1;
    }

    int result = is_negative(x);
    if(result == 1){
        return x;
    }
    else{
        int check = 1;
        check = check << size; 
        //while they are different
        //goes to most significant digit
        while(!(check & x)){
            check = check >> 1;
        }
        x = x ^ check;
    }
    return x;
}


/* combines all of the arguments into a single weatherlog_t entry as described below */
weatherlog_t pack_log_entry(unsigned int year, unsigned int month, unsigned int day,
                            unsigned int zip, int high_temp, int low_temp,
                            unsigned int precip, unsigned int avg_wind_speed) {
        //adds binary values to the uint64, the shifts to make room for the next number, and continues this process
        //For some reason, using the add function made it so that the uint64 could only hold 32 bits, which is why + is used here
    
        year = sub(year, 2000);
        weatherlog_t weather = year;

        weather = weather << 4;
        weather += month;
       // weather = add(weather, (unsigned long long int)month);

        weather = weather << 5;
        weather += day;
       // weather = add(weather, (unsigned long long int)day);
    
        weather = weather << 16;
        weather += zip;
       // weather = add(weather, (unsigned long long int)zip);
        
        weather = weather << 8;
        weather += high_temp;
     //  weather = add(weather, high_temp);

        weather = weather << 8;
        weather += low_temp;
      //  weather = add(weather, low_temp);
    
        weather = weather << 10;
        weather += precip;
       // weather = add(weather, precip);
  
        weather = weather << 7;
        weather += avg_wind_speed;
  //      weather = add(weather, avg_wind_speed);

    
    return weather;
}

//all of these get rid of unneeded bits by shifting to the left in order to delete unneeded information and them right to place the wanted information in the appropriate position
unsigned int get_year(weatherlog_t entry) {
   entry = entry >> 58;
   return entry;
}

unsigned int get_month(weatherlog_t entry) {
    entry =  entry << 6 ;
    entry = entry >> 60;
    return entry;
}

unsigned int get_day(weatherlog_t entry) {
    entry =  entry << 10 ;
    entry = entry >> 59;
    return entry;
}

unsigned int get_zip(weatherlog_t entry) {
    entry =  entry <<  15;
    entry = entry >> 48;
    return entry;
}

unsigned int get_high(weatherlog_t entry){
    entry =  entry <<  31;
    entry = entry >> 56;
    return entry;
}

unsigned int get_low(weatherlog_t entry) {
    entry =  entry <<  39;
    entry = entry >> 56;
    return entry;
}

unsigned int get_precip(weatherlog_t entry) {
    entry =  entry <<  47;
    entry = entry >> 54;
    return entry;
}

unsigned int get_wind(weatherlog_t entry) {
    entry =  entry <<  57;
    entry = entry >> 57;
    return entry;
}

/* weatherlog_t

A particular weather sensor called the WeatherJuicer 2000 TM stores a
log entry each day, representing weather activity from the
previous 24 hours. Each entry includes a:

- year :: 6 bits -- stored as the number of years since the year 2000.
- month :: 4 bits
- day :: 5 bits
- zip_code :: 16 bits
- high_temp :: in degrees Fahrenheit, stored as an 8-bit signed integer
- low_temp :: in degrees Fahrenheit, stored as 8-bit signed integer
- precipitation :: in mm. stored as a 10-bit unsigned integer.
- average_wind_speed :: 7 bits. unsigned int km/hr.

All of these are packed into a 64 bit unsigned integer in the above order.

For example, if on September 16, 2015, on Temple's main campus, which
is in zip code 19122, we have 15 mm of rain, a high temperature of 85
degrees, a low temperature of 65 degrees, and an average wind speed of
5 km/hour.

We'd store:
- year :: 2015, which is 15 years from 2000, so 001111
- month :: September, which is the 9th month, so 1001.
- day :: 16, which is 1 0000
- zip_code :: 19122 which is 0100 1010 1011 0010
- high_temp :: 85F, so 0101 0101
- low_temp :: 65F, so 0100 0001
- precipitation :: 35 mm so 00 0010 0011
- average wind speed :: 5 km/h, so 000 0101

And all would be packed into a single 64-bit unsigned integer:

00 1111 1001 10000 0100 1010 1011 0010 0101 0101 0100 0001 00 0010 0011 000 0101

OR

0011 1110 0110 0000 1001 0101 0110 0100 1010 1010 1000 0010 0001 0001 1000 0101

OR

0x3e609564aa821185


We define this weather log as its own datatype called weatherlog_t, which
under the covers is really a 64-bit unsigned int. This is done in the line:

typedef uint64_t weatherlog_t;
 
*/