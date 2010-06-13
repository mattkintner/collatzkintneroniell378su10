// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2010
// Glenn P. Downing
// --------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <cmath> // math


int countCycles(unsigned long, int);

// ------------
// collatz_read
// ------------

/**
 * reads two ints into i and j
 * @param  r a  std::istream
 * @param  i an int by reference
 * @param  j an int by reference
 * @return true if that succeeds, false otherwise
 */
bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_eval
// ------------

/**
 * @param  i the beginning of the range, inclusive
 * @param  j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
     int begin = -1;
     if(i < j){
        begin = i;
     }
     else{
        begin = j;
     }
     assert(begin != -1);

     int range = abs(i - j);
     int end = begin + range;

     int v = 0;
	  for(int k = begin; k <= end; k++){
			int temp = countCycles(k , 1);
			//int temp = countCycles2(k);
			if(v < temp){
				v = temp;
			}
		}
    assert(v > 0);
    return v;}

 // ----
 // countCycles
 // ----

 /**
  * @param  n the number being subjected for 3n+1 algorithm
  * @param  counter the number that keeps track of the cycle length for n
  * @return the cycle length for given n
  */
  
int countCycles(unsigned long n, int counter){
		assert(n > 0);		
		//n is 1
		if(n == 1){
			return counter;
		}
		//n is odd
		else if(n % 2 == 1){
			n = n + (n >> 1) + 1;
			counter += 2;
			return countCycles(n, counter);
			//return countCycles(3*n + 1, ++counter);
		}
		//n is even
		else{
			return countCycles(n/2, ++counter);
		}
	}


// -------------
// collatz_print
// -------------

/**
 * prints the values of i, j, and v
 * @param  w a std::ostream
 * @param  i the beginning of the range, inclusive
 * @param  j the end       of the range, inclusive
 * @param  v the max cycle length
 */
void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}
