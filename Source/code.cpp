/* Code.cpp */
/* Project1	Dave Pleteau and Jack Carson */
/* cpp file that contains the code class implementation */
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "code.h"

using namespace std;


code::code()
/**
* Initializes a code object's code length and range of digits to 0. 
* Doesn't set set flag to true as a code hasn't been created
* @param	none
* @retval	none
*/
{
	/* Initialize private code vars */
	nElements = 0; mRange = 0; set = false;
}//end code constr #1


code::code(uint32_t n, uint32_t m)
/**
* Initializes a code object's code length, range of digits and secret code
*			Sets set flag to true as a code has been generated
* @param	n:	code length
* @param	m:	range of digits
* @retval	none
*/
{
	/* Initialize private code vars */
	nElements = n; mRange = m;
	
}//end code constr #2


void code::genCode()
/**
* Populates nElements of secret code vector with random # between [0-mRange-1]
*			using sRand() and rand() methods
* @param	none
* @retval	none
*/
{
	//Picks a dynamic seed from global time
	srand((unsigned)time(0));

	for (uint32_t i = 0; i < nElements; i++)
	{
		//Using seed, gens pseudo-random # b/w 0 and mRange-1
		uint32_t randNum = rand() % (mRange);
		//Append randNum to secret code
		code_seq.push_back(randNum);
	}

	/* Indicate code has been set */
	set = true;
}//end code::genCode


void code::setCode(std::vector<uint32_t> newCode)
/**
* Sets the code vector of a code object using vector newCode
* @param	newCode: Vector that holds new code to store inside code object
* @retval   none
*/
{
	//Resize code_seq accordingly
	nElements = newCode.size();
	code_seq.resize(nElements);

	for (uint32_t i = 0; i < nElements; i++)
	{

		/* Copy Vector into code_seq obj */
		code_seq[i] = newCode[i];

	}

	/* Indicate Code Sequence has been set */
	set = true;
}//end code::setCode


std::vector<uint32_t> code::getCode() const
/**
* Returns the code vector of a code object
* @param	none
* @retval   code_seq: vector that holds the code sequence of a code object
*/
{
	return code_seq;
}//end code::getCode


ostream& operator<<(ostream &out, const code &aCode)
/**
* Global ostream operator overload for printing code object
* @param	out: ostream object (passed by ref) where we're writing to
* @param	aCode: code object (passed by ref) be inserted in out
* @retval   out: ostream obj addr that holds the info to be printed on the
*			command line.
*/
{
	out << "{";
	for (uint32_t i = 0; i < aCode.nElements; i++)
	{
		(i == aCode.nElements - 1) ? (out << aCode.code_seq[i] << "}") :
			(out << aCode.code_seq[i] << ", ");
	}
	return out;
}//end << operator overload for code obj

