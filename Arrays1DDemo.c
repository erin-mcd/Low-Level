/*
Erin McDonald
2/11/2019
CIS2107
Lab04
To design and implement functions to process 1D arrays
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

int fillArray(int a[],int high, int low, size_t size);
int findWithRange(int a[], int low, int high, size_t size);
int reverseArray(int a[], size_t size);
int findSequence(int a[], size_t size);
int reverseSelect(int a[],int high, int low, size_t size);

int main(void){
  int max;
  int a[SIZE];
  //Make the array
  fillArray(a,0,100, SIZE);
   for(size_t i = 0; i < 40; i++){
   if(i == 0){
      printf("Original:\n");
    }
    printf(" %d", a[i]);
  }

   //Test max
   max = findWithRange(a,0,10, SIZE);
  printf("\n\nMax between 0 and 10 = %d\n\n", max);
  //test reverseArray
  reverseArray(a, SIZE);
  for(size_t i = 0; i < 40; i++){
    if(i == 0){
      printf("Full Reverse:\n");
    }
   printf(" %d", a[i]);
  }
  //test reverseSelect
  printf("\n\nReversing between 3 and 10\n");
  reverseSelect(a,3, 10, SIZE);
  for(size_t i; i < 40; i++){
   printf(" %d", a[i]);
  }

  //Test findSequence
  printf("\n\nFinding Sequence");
  int seq = findSequence(a, SIZE);
  if(seq == -1){
      printf("sequence not found\n");
    }
  else{
  printf("sequence found at index %d\n", seq);
  }
 
}

//fill a 1d array
int fillArray(int a[],int low, int high, size_t size){
  for(size_t i = 0; i < size; i++){
    a[i] = low + rand() % (high + 1);
  }
}

//find max within a range
int findWithRange(int a[],int low, int high, size_t size){
  int max = low;
  for(size_t i = low; i <= high; i++){
    if(a[i] > max){
      max = a[i];
    }
  }
  return max;
}

//reverse entire array
int reverseArray(int a[], size_t size){
  int end = size - 1;
  int beg = 0;
  int temp;
  while(beg < end){
    temp = a[beg];
    a[beg] = a[end];
    a[end] = temp;
    beg++;
    end--;
  }
}

//reverse array through selected elements
int reverseSelect(int a[], int low, int high, size_t size){
  int temp;
  if(low >high){
    temp = low;
    low = high;
    high = temp;
  }
  if(low < 0 || high > (size -1)){
    printf("Index out of bounds. Please run the program again.");
    exit(0);
  }
  while(low < high){
    temp = a[low];
    a[low] = a[high];
    a[high] = temp;
    low++;
    high--;
  }
}

//find if a sequence is there or not
int findSequence(int a[], size_t size){
  int first;
  int sec;
  printf("\nEnter two numbers: \n");
  scanf(" %d", &first);
  scanf(" %d", &sec);
  for(size_t i = 0;i < size; i++){
    if(a[i] == first && a[i + 1] ==sec){
      return i;
    }
  }
  return -1;
}
