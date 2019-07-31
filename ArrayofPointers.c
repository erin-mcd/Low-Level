/*
Erin McDonald
CIS2017
Lab 05
Design and implement array of function pointer
2/18/2019
*/


#include <stdio.h>
#include <stdlib.h>
int rows;
int cols;
int end = 0;
void minimum(const int grades[][cols], size_t pupils, size_t tests);
void maximum(const int grades[][cols], size_t pupils, size_t tests);
void average(const int grades[][cols], size_t pupils, size_t tests);
void printArray(const int grades[][cols], size_t pupils, size_t tests);
void exi(const int grades[][cols], size_t pupils, size_t tests);

int main(void){


  void (*processGrades[])(const int grades[][cols], size_t pupils, size_t tests) = {printArray, minimum, maximum, average, exi};
  
 
    printf("Let's create a 2Dim array!\n\n\tHow many rows? ");
    scanf("%d", &rows);
    printf("\tHow many columns? ");
    scanf("%d", &cols);
    int a[rows][cols];
    
     for(int j = 0; j < rows; j++){
       for(int i = 0; i < cols; i++){
	 int input;
	 if(i == 0 && j == 0){
	 printf("\n\tenter [%d][%d]: ",j,i);
	 }
	 else{
	 printf("\tenter [%d][%d]: ",j,i);
	 }
	 scanf("%d", &input);
	 a[j][i] = input;
       }
     }
     while(end != 1){
     int result;
     int input;
     printf("\nEnter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all tests for each student\n\t4 End Program\n");
     scanf("%d", &input);
     (*processGrades[input])(a,rows,cols);
     }
}

void printArray(const int grades[][cols], size_t pupils, size_t tests){
  printf("                ");
  for (int i = 0; i < tests; i++){
    printf("[%d]  ", i);
  }

     for (size_t i = 0; i < pupils; i++){
       printf("\nstudentGrades[%ld] ", i);

          for (size_t j = 0; j < tests; j++){
	    printf("%-5d", grades[i][j]);
	  }
     }
}

void minimum(const int grades[][cols], size_t pupils, size_t tests){
    int lowGrade = 100;

    for(size_t i = 0; i < pupils; i++){
      for (size_t j = 0; j < tests; j++){
	if (grades[i][j] < lowGrade){
        lowGrade = grades[i][j];
    }
    }
    }
  printf("\nMinimum: %d\n", lowGrade);
}

void maximum(const int grades[][cols], size_t pupils, size_t tests){
    int highGrade = 0;

    for(size_t i = 0; i < pupils; i++){
      for (size_t j = 0; j < tests; j++){
	if (grades[i][j] > highGrade){
        highGrade = grades[i][j];
    }
    }
    }
  printf("\nMaximum: %d\n", highGrade);
}

void average(const int grades[][cols], size_t pupils, size_t tests){
    double total = 0;
    double average = 0;

    for(size_t i = 0; i < pupils; i++){ //for each student
      for(size_t j = 0; j < tests; j++){
	total += grades[i][j];
      }
   average = total / tests;
   printf("\nAverage grade of student %ld: %.2f\n", i, total);
   average = 0;
  }
}

  void exi(const int grades[][cols], size_t pupils, size_t tests){
  exit(0);
}
