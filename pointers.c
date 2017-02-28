/* pointers.c

   Name: Sarah Depew
   Resources used (websites, books other than our texts, peers): TA 

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
  //default is true, since the regions overlap in all other cases
  return true;
}

/* Changes the value in *a, *b, and *c so that *a, *b, and *c are
   in non-decreasing order. */
void minisort(int* a, int* b, int* c){
  int temp = 0; //temporary variable that stores the value for exchanging
  if(*a>*b){
    //swap a and b
    swap(a,b);
  }
  if(*b>*c){
    //swap b and c
    swap(b,c);
  }
  if(*a>*b){
    //swap a and b
    swap(a,b);
  }
  //Since there are only three values, they have to be sorted, now since this code accounts for the worst case
}

//function for swapping values
void swap(int* x, int* y){
  int temp = 0; 
  temp = *x;
  *x = *y;
  *y = temp;
}

/* Computes the sum of the ints that sit in memory between p
   (inclusive) and q (exclusive). You may assume that q comes
   after p -- that is, q >= p. */
int partial_sum(int* p, int* q){
  //sum variable to store the sum of the values
  int sum = 0;

  //adds all the values of the memory location to sum
  for(int* i=p; i<q; i++){
    sum+=*i;
  }
  //returns the sum and returns 0 if the for loop does not run
  return sum;
}

/* Check whether `n` array elements, starting at `start` and
   incrementing be `step`, all match, according to the rules
   of Tic Tac Toe. Returns X or O if there is a winner, or
   BLANK otherwise. */
int check_line(int* start, int step, int n){
  //for loop that runs through n array elements and checks that the previous and the current are the same 
  for(int i=1; i<n; i++){
    //printf("Value being checked: %d\n",(*(start+(step*i))));
    //if statement that checks if the values are the same and fails if not
    if((*(start))!=(*(start+(step*i)))){
      return BLANK;
    }
  }
  //the code reaches this point if all the values were the same
  return *start; //returns what is at start, which is either X or O or BLANK (this still returns if there is a row, column, or diagonal of blanks)
}

/* Check for a winner of Tic Tac Toe. Precondition:
   board points to a region of memory containing at least
   n^2 ints. Returns the winner of Tic Tac Toe, or BLANK
   if there is no winner. */

int tic_tac_toe_winner(int n, int* board)
{
  //variable that stores the return value of the winner of the game
  int val = 0;

  //Ways to win: row, column, diagonals (otherwise you did not win...)
  
  //check row 
  for(int i=0; i<n; i++){ 
    val =  check_line((board+(i*n)), 1, n); //checks each row of the board for a winner
    if(val){ //this if makes sure that the winner is not returned if it is a blank
      return val;
    }
  }
  
  //check columns
  //printf("%d\n", *board);
  for(int i=0; i<n; i++){
    val =  check_line((board+i), n, n); //checks each column for a solution
    if(val){ //this if makes sure that the winner is not returned if it is a blank
      return val;
    }
  }
    
  //check diagonal top left to bottom right
  //printf("%d\n", *board);
    val =  check_line(board, (n+1), n); //checks the diagonal for a solution
    if(val){ //this if makes sure that the winner is not returned if it is a blank
      return val;
    }
    
  //check top right to bottom left
    //printf("%d\n", *board);
    val =  check_line(board+n-1, (n-1), n); //checks the diagonal for a solution
    if(val){ //this if makes sure that the winner is not returned if it is a blank
      return val;
    }
    
    return 0; //default return value, since the default is that there are blanks and nobody won
}
