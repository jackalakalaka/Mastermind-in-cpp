#pragma once
/**response.h*/
/* Project1 Dave Pleteau	and Jack Carson	 */
/* Header file that defines the response class */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class response
{
private:
	uint32_t numCorrect; uint32_t numIncorrect;
    //bool set;
public:
    /* Constructor */
    response();


    /* Public functions */


	/* Setters */

	//Sets passed correct count
	void setCorrect(const uint32_t numCorr) { numCorrect = numCorr; };

	//Sets passed incorrect count
	void setIncorrect(const uint32_t numIncorr) { numIncorrect = numIncorr; };

	/* Getters */

	/* Returns correct count */
	uint32_t getCorrect() const { return numCorrect; }; 
	
	/* Returns incorrect count */
    uint32_t getIncorrect() const { return numIncorrect; };

	//Global equality operator overload for response obj's decln
	friend bool operator == (const response& r1, const response& r2);

	//Global ostream operator overload for printing response obj's decln
	friend ostream& operator << (ostream& ostr, const response& r);
};//end of response class

