**Ch 1 ... 7 8**

**Ch 6 ... 1 2 3 4 9 10**

**Ch 5 ... 5 6**

**Ch 8 ... 1 2 3 5 7 8 9**



**2/26/19 ...**

6.1 (heavy pill) ... Idea problem hard to think of. Interesting solution.

6.2 (probability) ... Easy, not interesting. Think intuitively.

6.3 (dominos) ... "Proof" is based on intuition, but interesting thought.

6.4 (ants walk) ... Trivial problem.

6.9 (100 locks) ... Not easy. Figured out up to the importance of factors.

6.10 (poison) ... Good problem. Should be able to solve next time. Requires CS-like mindset.

 

**2/28/19 ...**

[factorials.cpp](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/recursion/factorials.cpp)
... simple recursion example (CS32 lec 8)


**3/01/19 ...**

[pointerReview.cpp](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/pointerReview.cpp)
... basics of pointers

[array_element_sum.cpp](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/recursion/array_element_sum.cpp)
... simple recursion example (CS 32 lec 8)


**3/02/19 ...**

[print_array_backwards.cpp](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/recursion/print_array_elements_backwards.cpp)
... simple recursion example (CS 32 lec 8)


**3/03/19 ...**

[8.5 (recursive multiply)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch8/8.5_RecursiveMultiply.cpp) ... solved first time.

[8.1 (Triple Steps)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch8/8.1_TripleStep.cpp) ... Wrong answer 1st tme, do again.

[8.2 (Robot Grid)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch8/8.2_RobotGrid.cpp) ... still has errors (**incomplete!**)

[1.8 (Zero Matrix)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch1/1.8_ZeroMatrix.cpp) ... Brute force complete. Optimized solution incomplete.

**3/04/19 ...**

[1.7 (Rotate Matrix)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch1/1.7_RotateMatrix.cpp) ... Brute force complete. ~~"In place" solution incomplete. ...~~-> completed "in place" solution on 3/12/19

**3/05/19 ...**

Reading Big O chapter. Stuck with Problem 8 which involves sorting knowledge. Need to do sorting first to understand.
8.11...attempted but too difficult. Try again later...

Sent MacBook out for repair.

**3/06/19 ...**

MacBook back from repair.
Going over constructor/destructor notes (CS32 Lec 2.)

CS32 Lec 16 (intro to **graphs**).  Come back to breadth-first later (need to review queues first.)

CS32 Lec 2 (**contructors, destructors, class composition**)

slide 30 is essentially what you need to know about constructor/destructor execution ordering!)

CS32 Lec 2 (slide 41 is essentially what you need to know about passing variables to classes w/ classes (initialization list)!)

**3/07/19 ...**

CS32 Lec 3 (**pointers** ... carrying over to next day)

the **"this" pointer**... slide 27

**3/08/19 ...**

CS32 Lec 3 (**pointers** ...completed)

**copy constructors** ... when a class has a pointer member variable, must create own copy constructor to prevent destructor from erasing memory when copied instance gets terminated.


**dynamic variables** ... **new** and **delete** command ... slide 37~.

slide 22 shows the two ways to use class methods (*ptr).func() or ptr->func()

**3/09/19 ...**

CS32 Lec 5 (**stacks and queues** ...skipped infix to post fix conversion algorithm, review psudo code for maze ...slide 23 & 35)


**3/10/19 ...**

CS32 Lec 14 (**hash tables** ... carrying over to next day)... went through "closed" hash tables. Should review insert (p.27) and search (p.30) implementation.


**3/11/19 ...**

CS32 Lec 14 (**hash tables** ... completed)... "open" hash tables, (regular) tables. Slide 66 important. continuing. map, vector not reviewed yet, but appeared.

**3/12/19 ...**

[1.7 (Rotate Matrix)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch1/1.7_RotateMatrix.cpp) ... Completed previously skipped "in place" solution.

[Fibonacci Series w **memoization**](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch8/Fibonacci_memoization.cpp) ... Simple recurssion problem using **memoization**. Good practice to grasp the concept.

**3/13/19 ...**

CS32 Lec 4 (**Assignment Operators**, **Linked lists**)

nullptr

[8.9 (Parentheses)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch8/8.9_Parens.cpp) ... Very time consuming. Probably didn't solve it the way it was intended. Coming up with the binary representation was the trick. Alternative (more elegant) solutions wanted.

[8.7 (Permutations without dups)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch8/8.7_permutations_without_dups.cpp) ... Seemingly trivial problem. Shouldn't even be included in the recursion chapter.


**3/14/19 ...**

[8.8 (Permutations with dups)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch8/8.8_permutations_with_dups.cpp) ... Good review of math combinations (probability). Didn't use recursion.

[8.3 (Magic Index)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch8/8.3_Magic_Index.cpp) ... Not interesting. Why is this included as a problem?


[5.5 (Debugger)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch5/5.5_Debugger.cpp) ... all about knowing what (for example) 13 & 7 will do.

[5.6 (Conversion)](https://github.com/kyeokabe/crackingCodingInterview/blob/master/code/ch5/5.6_Conversion.cpp) ... knowing "&" (same as 5.5) helps. Made a small mistake forgetting to implement overlap_digits function.


**3/15/19 ...**

6.6 (Blue-Eyed Island) ... c = 3 solution seems strange. (day 1 behaviour should change.)
