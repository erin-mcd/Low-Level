/*
Erin McDonald
CIS2107
Lab 6
2/25/2019
To design and implement functions to process pointers
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int tortMove();
int hareMove();
void changeLocation(int *tPtr, int *hPtr);

int main(){
  int hare = 1;
  int tort = 1;

  //start
  printf("ON YOUR MARK, GET SET\nBANG               !!!\nAND THEY'RE OFF    !!!!\n");
  while(hare < 70 && tort < 70){
    changeLocation(&tort, &hare);

    //if they go behind the start, put them back at the start
    if(hare < 1){
      hare = 1;
    }
    if(tort < 1){
      tort = 1;
    }
   
  for(int i = 1; i < hare; i++){
    printf(" ");
  }
  //tie
   if(hare == tort){
     printf("OUCH!!!\n"); 
    }
   else{
     printf("H\n");
   }
  
   for(int i = 1; i < tort; i++){
    printf(" ");
  }
   //tie
    if(hare == tort){
     printf("OUCH!!!\n");
    }
    else{
  printf("T\n");
    }
    //delay
    usleep(200000);
  }

  //after someone wins
  if(hare >= 70 && tort < 70){
    printf("Hare wins. Yuch.\n");
  }
  else if(tort >= 70 && hare < 70){
    printf("TORTOISE WINS!!! YAY!!!\n");
  }
  else{
    printf("IT'S A DRAW\n");
  }
}

//determine hare direction/number of steps
int hareMove(){
  int hmove = rand() % 10 + 1;
  if(hmove >= 1 && hmove <= 2){
    return 0;
  }
  if(hmove >= 3 && hmove <= 4){
    return 9;
  }
  if(hmove == 5){
    return -12;
  }
  if(hmove >= 6 && hmove <= 8){
    return 1;
  }
  else{
    return -2;
  }
}

//determine tortoise direction/number of steps
int tortMove(){
  int tmove = rand() % 10 + 1;
  if(tmove >= 1 && tmove <= 5){
    return 3;
  }
  if(tmove >= 6 && tmove <= 7){
    return -6;
  }
  else{
    return 1;
  }
}

//actually change the location of the tortoise and hare with pointers
void changeLocation(int *tPtr, int *hPtr){
  int tMove = tortMove();
  int hMove = hareMove();

  *tPtr = *tPtr + tMove;
  *hPtr = *hPtr + hMove;
}
