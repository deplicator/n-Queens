Homework #2 - Eight Queens
==========================
James Pryor  
COMP3053 Analysis of Algorithms  

Description
-----------
Displays a text based board for all solutions to the [n-queens problem][1].


Assignment
----------

### Problem
> The 8-queens puzzle is the problem of placing 8 queens on an 8×8 chessboard such that no two 
> queens attack each other. There are multiple solutions and the following is one solution to the 
> problem. In this homework, you need to design a brute-force algorithm and implement it using 
> either C++/Java to find one solution. The program should display the eight queues positions either
> in text or in a graphic format.

### Pseudo Code
    
    FUNCTION solve(index = 0)
        IF all queens have been found THEN
            you're done, stop recursion.
        ELSE
            FOR size of the game board
                IF this spot cannot be attacked by an existing queen THEN
                    place a queen here
                    solve(index + 1);
                END IF
            END FOR
        END IF

### Solution
This is the basic algorithm, there will of course, need to be more. For starters another function
for `this spot cannot be attacked by an existing queen`. This implementation makes use of the fact
each row must have a queen. If all the spots in the next row are attackable by an existing queen
the `FOR size of the game board` loop will try the next spot in the previous row.

For this project I did study the [solutions][2] [implemented][3] [by][4] [others][5]. In doing so I
realized how easy it was to make my function that returns the solution to one board into a function
that returns all the solutions. Moving to user inputted nxn instead of 8x8 was trivial (compared to 
the time I'm ashamed to admit it took me to figure out the solution logic).

I moved to a class structure to make use of class-wide variables, also I feel passing arrays into
functions to be a messy process in C++.


### Implementation
Default execution will display all solutions for an 8x8 game board. Appending a number behind the 
execution command will display all solutions for nxn board. For example:

    queens.exe 10

Will return the 724 solutions for a 10x10 board. The program has only been tested to 13x13;
expect the results to take several minutes at anything larger. It should be noted there is no data
validation on this, anything other than numbers will yield unexpected results.

It can be beneficial to send the output to a text file. The output is bulky, running the program 
with an n of 13 will yield a 130 MB file.

    queens.exe 9 > results.txt

| n  | distinct results | output size  |  estimated time* |
|---:|-----------------:|-------------:|-----------------:|
|  1 |                1 |    139 bytes |        0 seconds |
|  2 |                0 |              |                  |
|  3 |                0 |              |                  |
|  4 |                2 |    654 bytes |        0 seconds |
|  5 |               10 |       4.2 kB |        0 seconds |
|  6 |                4 |       2.2 kB |        0 seconds |
|  7 |               40 |      26.6 kB |        0 seconds |
|  8 |               92 |      74.5 kB |     0.02 seconds |
|  9 |              352 |     343.5 kB |     0.07 seconds |
| 10 |              724 |     840.5 kB |     0.23 seconds |
| 11 |            2,680 |       3.6 MB |     0.23 seconds |
| 12 |           14,200 |      22.4 MB |     0.94 seconds |
| 13 |           73,712 |     133.0 MB |     6.36 seconds |
| 14 |          365,596 |              |                  |
| 15 |        2,279,184 |              |                  |
| 16 |       14,772,512 |              |                  |
| 17 |       95,815,104 |              |                  |
| 18 |      666,090,624 |              |                  |
| 19 |    4,968,057,848 |              |                  |
| 20 |   39,029,188,884 |  over 20GB** | tired of waiting |

 *  Output time in result text file running in an Ubuntu 13.10 virtual machine on an Intel Corei7.
    Results in terminal will take longer.
 ** Stopped test, was taking too long and too much space.


[1]: http://en.wikipedia.org/wiki/Eight_queens_puzzle
[2]: http://jsomers.com/nqueen_demo/nqueens.html
[3]: http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
[4]: http://csc.columbusstate.edu/bosworth/SearchProblems/N_Queens.htm
[5]: http://www.eightqueen.becher-sundstroem.de/
