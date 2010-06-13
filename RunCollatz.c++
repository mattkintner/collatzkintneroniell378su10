// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2010
// Glenn P. Downing
// -------------------------------

/*
To run the program:
    % g++ -ansi -pedantic -Wall RunCollatz.c++ -o RunCollatz.app
    % valgrind RunCollatz.app < RunCollatz.in >& RunCollatz.out

To configure Doxygen:
    % doxygen -g
That creates the file "Doxyfile".
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    % doxygen Doxyfile
*/

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout, ios_base

#include "Collatz.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O

    int i;
    int j;

    while (collatz_read(cin, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(cout, i, j, v);}

    return 0;}
