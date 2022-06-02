/************************************************************
* Exception Handle, File exception.h
* Thiết kế hàm chia 2 số có xử lý ngoại lệ: 'Chia bởi zero'
************************************************************/

#include <iostream>
#include <stdexcept>
using namespace std;

/*
* Exception Handling
* One of the avantages of the exception handling approach is
* that we can design functions that can throw an exception.
* It is the responsibility of the caller to handle the exception.
*/
/* Problem: Division by zero! */
// (1) Design functions that can throw an exception
// Solution 1: Using the try-catch block to detect an error
// throw by a function
int quotient(int first, int second) {
	if (second == 0)
		throw 0;
	return (first / second);
}

// Solution 2: Using an object of invalid_argument
// to detect division by zero in a function
// stdexcept: Standard Exception Classes
int stdQuotient(int first, int second) {
	if (second == 0)
		throw invalid_argument("Error! Divide by zero!");
	return first / second;
}