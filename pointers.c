/* pointers.c

   Name: Sarah Depew
   Resources used (websites, books other than our texts, peers): TA, 

*/

#include <stdlib.h>
#include <stdio.h>
#include "pointers.h"

/* Returns whether or not the region pointed to by p1 (of length n)
   overlaps with the region pointed to by p2 (of length m). Do not
   assume that p2 is greater than p1. */
bool overlaps(int n, int* p1, int m, int* p2)
{
  if((p1+n)<=p2){ //the regions have no overlap at all and p1 starts and ends before p2
      return false;
  }

  else  if(p2+m<=p1){ //the regions have no overlap at all and p1 starts before p2 ends
      return false;
  }

  return true;
}

  /*
  if(p1<p2){
    
    else{
      return true;
    }
  }

  else if(p1==p2){
    return true; 
  }

  else{ //p1>p2
    
    else{
      return false;
    }
  }
  return false;
 
}
 */

/* Changes the value in *a, *b, and *c so that *a, *b, and *c are
   in non-decreasing order. */
void minisort(int* a, int* b, int* c)
{
  int temp = 0;

   printf("\n%d, %d, %d\n", *a, *b, *c);
   
  //Do I need to move a?
  if(*a<=*b){
    if(*a<=*c){
      //no need to move the value a references
    }
    else{
      temp = *a;
      *a = *c;
      *c = temp;
    }
  }

  else if(*a>*c){
     temp = *c;
     *c = *a;
     *a = temp;
  }
  
  else{
      temp = *b;
      *b = *a;
      *a = temp;
    
  }
    printf("\n%d, %d, %d\n", *a, *b, *c);
 
  //Do I need to move b? a is in the correct location, now
  if(*b<=*c){
    //there is not need to do anything
  }
  
  else{
  //Do I need to move c?
    temp = *c;
     *c = *b;
     *b = temp;
  }
   printf("\n%d, %d, %d\n", *a, *b, *c);
}

/* Computes the sum of the ints that sit in memory between p
   (inclusive) and q (exclusive). You may assume that q comes
   after p -- that is, q >= p. */
int partial_sum(int* p, int* q)
{
  int sum = 0;
  //printf("%d\n", *p);
  //printf("%d\n", *q);
  
  for(int* i=p; i<q; i++){
    //printf("%d", *i); 
    //printf("%d\n", *p); 
    sum+=*i;
  }
  return sum;
}

/* Check whether `n` array elements, starting at `start` and
   incrementing be `step`, all match, according to the rules
   of Tic Tac Toe. Returns X or O if there is a winner, or
   BLANK otherwise. */
int check_line(int* start, int step, int n)
{
  /* WRITE THIS FUNCTION */
  return 0;
}

/* Check for a winner of Tic Tac Toe. Precondition:
   board points to a region of memory containing at least
   n^2 ints. Returns the winner of Tic Tac Toe, or BLANK
   if there is no winner. */
int tic_tac_toe_winner(int n, int* board)
{
  /* WRITE THIS FUNCTION */
  return 0;
}


int main(void){
  int x = 4,  y = 1,  z = 5;
   minisort(&x, &y, &z);
 
  
  int xs[] = {4, 3, 8, 2, 7};
  int f = partial_sum(xs, xs+4);
  printf("%d\n", f);
  
  return 0; 
}
 

