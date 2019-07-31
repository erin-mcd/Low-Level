/*
Erin McDonald
CIS2017
Lab 05
Design and implement functions to procress 2Darrays.
2/18/2019
*/


#include <stdio.h>
int rows;
int cols;
int max(int a[rows][cols], int rows, int cols);
int rowSum(int a[rows][cols],int row, int cols);
int columnSum(int a[rows][cols],int col, int rows);
int isSquare(int row, int col);
int displayOutputs(int a[rows][cols], int rows, int cols);

  int main(){
   
    printf("Let's create a 2Dim array!\n\n\tHow many rows? ");
    scanf("%d", &rows);
    printf("\tHow many columns? ");
    scanf("%d", &cols);
    int a[rows][cols];

    //enter array
     for(int j = 0; j < rows; j++){
       for(int i = 0; i < cols; i++){
	 int input;
	 if(i == 0 && j == 0){
	 printf("\n\tenter [%d][%d]:",j,i);
	 }
	 else{
	 printf("\tenter [%d][%d]: ",j,i);
	 }
	 scanf("%d", &input);
	 a[j][i] = input;
       }
     }
    
     //test isSquare
    int sq = isSquare(rows, cols);

    for(int i = 0; i < rows; i ++){
      //test rowSum
         int sum = rowSum(a,i,cols);
	 if(i == 0){
	    printf("\nSum of row %d = %d\n",i, sum);
	 }
	 else{
	 printf("Sum of row %d = %d\n",i, sum);
	 }
    }
    for(int i = 0; i < cols; i ++){
      //test columnSum
      int sum = columnSum(a,i,rows);
      if(i == 0){
	printf("\nSum of column %d = %d\n",i, sum);
      }
      else{
	 printf("Sum of column %d = %d\n",i, sum);
      }
    }

    //test max
    int ma = max(a, rows, cols);
    printf("\nMax is %d", ma);
    
    //the rest of testing isSquare
    if(sq == 1){
      printf("\n\nThis is a square array.\n");
    }
    else{
      printf("\n\nThis is not a square array.\n");
    }
    
    //test displayOutputs
    displayOutputs(a,rows, cols);
}

int isSquare(int row, int col){
  if(row == col){
    return 1;
  }
  return 0;
}
int max(int a[rows][cols], int rows, int cols){
  int max = a[0][0];
  for(int j = 0; j < rows; j++){
  for(size_t i = 0; i < cols; i++){
    if(a[j][i] > max){
      max = a[j][i];
    }
  }
  }
  return max;
}

int rowSum(int a[rows][cols],int row, int cols){
  int sum = 0;
  for(size_t i = 0; i < cols; i++){
      sum += a[row][i];
   }
  return sum;
}

int columnSum(int a[rows][cols],int col, int rows){
  int sum = 0;
  for(size_t i = 0; i < rows; i++){
      sum += a[i][col];
   }
  return sum;
}

int displayOutputs(int a[rows][cols], int rows, int cols){
  printf("\nHere is your 2Dim array:\n");
  for(int j = 0; j < rows; j++){
    printf("[");
      
  for(int i =0; i < cols; i++){
    if(i == 0){
    printf("%d", a[j][i]);
    }
    else{
    printf(", %d", a[j][i]);
    }
    if(i == cols - 1){
      printf("]\n");
    }
    }
  }
}
