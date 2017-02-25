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
bool overlaps(int n, int* p1, int m, int* p2){
  if((p1+n)<=p2) //the regions have no overlap at all and p1 starts and ends before p2 even starts
      return false;
  else  if(p2+m<=p1) //the regions have no overlap at all and p1 starts before p2 ends
      return false;
  //default is true
  return true;
}

/* Changes the value in *a, *b, and *c so that *a, *b, and *c are
   in non-decreasing order. */
void minisort(int* a, int* b, int* c)
{
  bool sorted = false;
  int smallest_value = *a;
  int temp = 0; 
  
  while(!sorted){
    if(smallest_value>*b && smallest_value>*c){
      // a is largest, so put it in place of c
      temp = *a;
      *a = *c;
      *c = temp;
      if(*a<=*b){
	sorted = true;
      }
      else{
	// a>b, but a<c&&b<c
	 temp = *a;
	 *a = *b;
	 *b = temp;
	 sorted = true; 
      }
    }
    else if(smallest_value>*b&&smallest_value<=*c){
      //a is larger than b, but smaller than c
      //need to switch a and b to be sorted
      temp = *a;
      *a = *b;
      *b = temp;
      sorted = true;
    }
    else if(smallest_value>*c && smallest_value<=*b){
      //a is smaller than b but larger than c so need to switch a and c and then switch b and c
      temp = *c;
      *c = *a;
      *a = temp;
      
      temp = *b;
      *b = *c;
      *c = temp;
      sorted = true;
    }
    else{
      //anything else that fails is starting with a<b and a<c, so a is smallest
      if(*b<=*c){
	sorted = true;
      }
      else{
	//need to switch b and c
	temp = *b;
	*b = *c;
	*c = temp;
	sorted = true; 
      }
    }
  }
}

/* Computes the sum of the ints that sit in memory between p
   (inclusive) and q (exclusive). You may assume that q comes
   after p -- that is, q >= p. */
int partial_sum(int* p, int* q)
{
  int sum = 0;

  //adds all the values of the memory location to sum
  for(int* i=p; i<q; i++){
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
  for(int i=0; i<n; i++){
    if((*(start))!=(*(start+(step*i)))){
      return BLANK;
    }
  } 
  return *start; //returns what is at start, which is either X or O or BLANK (this still returns if there is a row, column, or diagonal of blanks)
}

/* Check for a winner of Tic Tac Toe. Precondition:
   board points to a region of memory containing at least
   n^2 ints. Returns the winner of Tic Tac Toe, or BLANK
   if there is no winner. */

int tic_tac_toe_winner(int n, int* board)
{
  int val = 0;

  //Ways to win: row, column, diagonals (otherwise you did not win...)
  
  //check rows
  //printf("%d\n", *board); 
  for(int i=0; i<n; i++){ 
    val =  check_line((board+(i*n)), 1, n); //checks each row
    if(val){
      return val;
    }
  }
  
  //check columns
  //printf("%d\n", *board);
  for(int i=0; i<n; i++){
    val =  check_line((board+i), n, n); //checks each column for a solution
    if(val){
      return val;
    }
  }
    
  //check diagonal top left to bottom right
  //printf("%d\n", *board);
    val =  check_line(board, (n+1), n); //checks the diagonal for a solution
    if(val){
      return val;
    }
    
  //check top right to bottom left
    //printf("%d\n", *board);
    val =  check_line(board+n-1, (n-1), n); //checks the diagonal for a solution
    if(val){
      return val;
    }
    
    return 0; //default return value
}
