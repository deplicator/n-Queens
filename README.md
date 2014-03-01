Homework #2 - Eight Queens
==========================
James Pryor  
COMP3053 Analysis of Algorithms  

[github.com/deplicator/n-Queens][git]

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
                    do some recursion, solve(index + 1) 
                END IF
            END FOR
        END IF

### Solution
This is the basic algorithm, there will of course, need to be more. For starters another function
for `this spot cannot be attacked by an existing queen`. This implementation makes use of the fact
each row must have a queen. If all the spots in the next row are attackable by an existing queen
the `FOR size of the game board` loop will try the next spot in the previous row.

For this project I did study the [solutions][2] [implemented][3] [by][4] [others][5]. In doing so I
realized how easy it was to alter my function that returns the solution of one board into one that
returns all solutions. Moving to user inputted nxn instead of 8x8 was trivial (compared to the time 
I'm ashamed to admit it took me to figure out the solution logic). With further tweaking I came to 
realize the game board can be represented by a single dimension array by using the index as columns.

I moved to a class structure to make use of class-wide variables, also I feel passing arrays into
functions to be a messy process in C++. This is also the first program I've written to make use of a
`makefile`, albeit it is not necessary in the least.

### Implementation
It can be compiled with the `makefile`, just type;

    make
    
by compiling with g++;

    g++ main.cpp nQueen.cpp -o queens
    
or by copying and pasting `main.cpp`, `nQueens.cpp`, and `nQueens.h` into Visual Studios (this has
been tested in Visual Studios 2010).

Default execution will display all solutions for an 8x8 game board. Appending a number behind the 
execution command will display all solutions for nxn board. For example:

    queens.exe 10

Will return the 724 solutions for a 10x10 board. The program has only been tested to 13x13; expect 
results of higher n's take several minutes. It should be noted there is little data validation on 
this. The program will not allow for numbers higher than 26 (alphabetical display limitations) and 
anything other than numbers will yield unexpected results.

It can be beneficial to send the output to a text file. The output is bulky (some examples in 
[git repository][git]), running the program with an n of 13 will yield a 130 MB file.

    queens 9.exe > results.txt

| n  | distinct results | output size  | estimated time** |
|:--:|-----------------:|-------------:|-----------------:|
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
| 20 |   39,029,188,884 | over 20GB*** | tired of waiting |

 **  Output time in result text file running in an Ubuntu 13.10 virtual machine on an Intel Corei7.
     Results in terminal will take longer.  
 *** Stopped test, was taking too long and too much space.

### Interesting Notes
I included the timing results to make it a bit more interesting, but discovered running in Ubuntu 
versus Windows to yield different results. This is not surprising, but I did find it curious running
in the Linux terminal and outputting to a file from Linux gave the same (or at least very close to)
amount of time passed.

It was also very obvious in Linux the time displayed was not how long it took the terminal to 
display the results. For example, running queen 12x12 in the terminal showed 0.94 seconds to 
complete, but I observed it taking several seconds to complete. My theory is the computations are 
finished in 0.94 seconds, but it takes longer to print 14 thousand boards.

Under Windows, running an 8x8 solution would take 2.587 seconds in the command window. Outputting 
the result to a file showed it took 0.023 seconds. This leads me to believe (but by no means is 
conclusive), Windows takes into account the time to display results but runs about the same as 
Linux.

This is anecdotal; there are several factors not taken into consideration. No less interesting 
though.


[git]: https://github.com/deplicator/n-Queens
[1]: http://en.wikipedia.org/wiki/Eight_queens_puzzle
[2]: http://jsomers.com/nqueen_demo/nqueens.html
[3]: http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
[4]: http://csc.columbusstate.edu/bosworth/SearchProblems/N_Queens.htm
[5]: http://www.eightqueen.becher-sundstroem.de/
