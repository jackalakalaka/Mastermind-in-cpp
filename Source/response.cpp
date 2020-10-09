/* response.cpp */
/* Project1	Dave Pleteau and Jack Carson */
/* cpp file that contains the response class implementation */
#include <iostream>
#include <string>
#include <vector>
#include "response.h"

using namespace std;

response::response()
/**
* Initializes a guess vector's response
* @param	none
* @param	none
* @retval	none
*/
{
	//Initialize private response vars
	numCorrect=0; numIncorrect=0;
}//end response constr


bool operator == (const response& r1, const response& r2) {
/**
* Global equality operator overload for response obj's impln
* @param	r1: first response
* @param	r2: second response
* @retval	bool: whether responses are equal or not
*/
	return (r1.numCorrect == r2.numCorrect &&
		r1.numIncorrect == r2.numIncorrect);
}//end == operator overload for response obj's


ostream& operator << (ostream& ostr, const response& r) {
/**
* Global ostream operator overload for printing response obj's impln
* @param	r1: default ostream obj
* @param	r: response to print
* @retval	ostream&: addr of ostream obj for what to print
*/
	ostr << '(' << r.numCorrect << ',' << r.numIncorrect << ')';
	return ostr;
}//end << operator overload for response obj
