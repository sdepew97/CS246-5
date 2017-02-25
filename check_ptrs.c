/* check_ptrs.c

   Name: Sarah Depew

   Unit tests for the pointer functions.
*/

#include <stdbool.h>
#include <check.h>

#include "pointers.h"

START_TEST(overlaps_test)
{
  int a[5];
  int b[5];
  int c[5]; 

  ck_assert(overlaps(5, a, 5, a));          // an array overlaps itself
  ck_assert(overlaps(5, a, 1, a));          // even if the lengths are different
  ck_assert(!overlaps(5, a, 5, b));         // different arrays don't overlap
  ck_assert(!overlaps(5, b, 5, c));         // different arrays don't overlap
  ck_assert(overlaps(5, a, 2, a + 3));      // these regions overlap
  ck_assert(overlaps(5, a, 4, a + 1));      // these regions overlap 
  ck_assert(!overlaps(3, a, 2, a + 3));     // these touch, but don't overlap
}
END_TEST

START_TEST(minisort_test)
{
 //variables for the tests

  //all cases for the tests
  int a = 1, b = 2, c = 3; //a<b<c
  int d = 1, e = 3, f = 2; //a<c<b
  int g = 2, h = 1, i = 3; //b<a<c
  int j = 3, k = 2, l = 1; //c<b<a
  int m = 2, n = 3, o = 1; //b<c<a
  int p = 3, q = 1, r = 2; //c<a<b
  int x = 4, y = 1, z = 5; //provided 
  int s = 12, t = -2, u = 3; //random

  minisort(&a, &b, &c);
  minisort(&d, &e, &f);
  minisort(&g, &h, &i);
  minisort(&j, &k, &l);
  minisort(&m, &n, &o);
  minisort(&p, &q, &r);
  minisort(&s, &t, &u);
  minisort(&x, &y, &z);
  
  ck_assert(a == 1 && b == 2 && c == 3);
  ck_assert(d == 1 && e == 2 && f == 3);
  ck_assert(g == 1 && h == 2 && i == 3);
  ck_assert(j == 1 && k == 2 && l == 3);
  ck_assert(m == 1 && n == 2 && o == 3);
  ck_assert(p == 1 && q == 2 && r == 3);
  
  ck_assert(x == 1 && y == 4 && z == 5);
  ck_assert(s == -2 && t == 3 && u == 12);
}
END_TEST

START_TEST(partial_sum_test)
{
  int xs[] = {4, 3, 8, 2, 7};
  ck_assert_int_eq(partial_sum(xs, xs+4), 17);
  ck_assert_int_eq(partial_sum(xs, xs+3), 15);
}
END_TEST

START_TEST(check_line_test)
{
  int xs[] = {X, BLANK, X, O, X, BLANK};
  ck_assert_int_eq(check_line(xs, 2, 3), X);
  ck_assert_int_eq(check_line(xs, 1, 3), BLANK);
  ck_assert_int_eq(check_line(xs+1, 4, 4), BLANK);
}
END_TEST

START_TEST(tic_tac_toe_test)
{
  
  int board1[3][3] = { {O, O, X},
		       {X, X, O},
		       {X, O, X} };
  ck_assert_int_eq(tic_tac_toe_winner(3, (int*)board1), X);

  int board2[2][2] = { {BLANK, O},
		       {X, BLANK} };
  ck_assert_int_eq(tic_tac_toe_winner(2, (int*)board2), BLANK);
  
  int board3[3][3] = { {X, X, X},
		       {X, X, O},
		       {X, O, X} };
  ck_assert_int_eq(tic_tac_toe_winner(3, (int*)board3), X);

  //test winning with a left,top diagonal
  int board4[4][4] = { {O, X, X, X},
		       {O, O, X, X},
		       {X, X, O, X},
                       {O, X, X, O} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board4), O);

  //test winning with a right, top diagonal
  int board5[4][4] = { {O, X, X, X},
		       {O, O, X, X},
		       {X, X, O, O},
                       {X, X, O, X} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board5), X);
  
  //test winning with a top row
  int board6[4][4] = { {X, X, X, X},
		       {O, O, O, X},
		       {X, X, O, O},
                       {X, O, X, X} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board6), X);

   //test winning with a top row
  int board7[4][4] = { {O, X, X, X},
		       {O, O, O, O},
		       {X, X, O, O},
                       {X, O, X, X} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board7), O);

   //test winning with a middle row
  int board8[4][4] = { {X, X, X, X},
		       {O, O, O, X},
		       {X, X, X, X},
                       {X, O, X, O} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board8), X);

   //test winning with a bottom row
  int board9[4][4] = { {X, X, X, X},
		       {O, O, O, X},
		       {X, X, O, O},
                       {X, O, X, X} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board9), X);

   //test winning with first column
  int board10[4][4] = {{O, X, X, X},
		       {O, O, O, X},
		       {O, X, O, O},
                       {O, O, X, X} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board10), O);

   //test winning with first column
  int board11[4][4] = {{O, X, X, X},
		       {O, O, O, X},
		       {O, X, O, O},
                       {O, O, X, X} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board11), O);

  //test winning with second column
  int board12[4][4] = {{O, X, X, X},
		       {X, X, O, X},
		       {O, X, O, O},
                       {O, X, X, X} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board12), X);

   //test winning with third column
  int board13[4][4] = {{O, X, O, X},
		       {O, O, O, X},
		       {O, X, O, O},
                       {X, O, O, X} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board13), O);

   //test winning with last column
  int board14[4][4] = {{O, X, X, X},
		       {X, O, O, X},
		       {O, X, O, X},
                       {O, O, X, X} };
  ck_assert_int_eq(tic_tac_toe_winner(4, (int*)board14), X);
  
  int board15[2][2] = {{X, O},
		       {X, BLANK}};
  ck_assert_int_eq(tic_tac_toe_winner(2, (int*)board15), X);
}
END_TEST

// the main() function for unit testing is fairly prescribed.
// Just copy & paste, but make sure to update the test names!


int main()
{
 
  // `check` allows for multiple test suites, but we'll always
  // just have one, called "main"
  Suite* s = suite_create("main");

  // Inside a suite are potentially many `TCase`s.
  TCase* tc = tcase_create("matrix");

  // Each TCase can have many individual testing functions.
  tcase_add_test(tc, overlaps_test);
  tcase_add_test(tc, minisort_test);
  tcase_add_test(tc, partial_sum_test);
  tcase_add_test(tc, check_line_test);
  tcase_add_test(tc, tic_tac_toe_test);

  // Having set up the TCase, add it to the suite:
  suite_add_tcase(s, tc);

  // To run the tests, we need a runner:
  SRunner* sr = srunner_create(s);

  // You can see options for running only some of the tests at
  // the documentation link above. The CK_NORMAL indicates to
  // print only failing tests.
  srunner_run_all(sr, CK_NORMAL);

  // after running, we can retrieve the number of failures
  int number_failed = srunner_ntests_failed(sr);

  // We're done now with the testsuite, so dispose of it properly
  srunner_free(sr);

  // conveniently, number_failed makes a nice exit code.
  // a non-zero answer means a failed test!
  return number_failed;
}
			    
