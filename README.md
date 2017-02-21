---
title: CS 246 Assignment 5
---

<div id="header">

| **CS 246 Assignment 5**
| due 12:55pm on Thursday, March 2, 2017

</div>

[Link back to syllabus](http://cs.brynmawr.edu/cs246/syllabus.html)

[Click here to start assignment](TODO)

Like all assignments, you will complete this assignment via
GitHub. See [the submission instructions](../submission.html)
for how to get the starter code and how to submit this
assignment.

This assignment introduces the notion of *flex* questions. A flex
question is *optional*. If you complete it, it will be graded as part
of the homework assignment. If you don't, then the question is
completely ignored. For example, the one non-flex question in this
assignment is worth 30 points. If you complete a 20-point flex question
as well, then your assignment is graded out of a total of 50 points. This
lessens the import of the non-flex question. Regardless of how many
points this one assignment is worth, it still counts as much as other
assignments when calculating the final grade at the end of the semester.
In other words, even if you complete only the non-flex question (30 points),
then this 30-point assignment counts as much as a 100-point assignment.

All the functions you are to write are in the `pointers.c` file. Unit
tests appear in `check_ptrs.c`; some tests are already there. Use these
tests to understand the functions better. You may wish to write more.
You may also write a `main` if you like, but it
is not necessary. If you do this, do *not* put the `main` function in
`pointers.c`, as that would prevent you from unit-testing your functions.
Do submit a `Makefile` with your work.

1. **Overlapping arrays**

    Write the function `overlaps`, as described in the file and tested in `
