#pragma once
/**code.h*/
/* Project1 Dave Pleteau	and Jack Carson	 */
/* Header file that defines the code class */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class code
{
private:
    uint32_t nElements;
    uint32_t mRange;
    vector<uint32_t> code_seq;

    //Flag that indicates whether code obj has been filled w/ vals yet
    bool set;
public:
    /* Constructor */
    code();
    code(uint32_t n, uint32_t m);

    /* Public functions */
    void genCode();

    /* Setters */
    void setCode(std::vector<uint32_t> v);
    /* Getters */
    vector<uint32_t> getCode() const; /* Return code vec */
    uint32_t getCodeLen() const { return nElements; } /* Return code length */
    uint32_t getDigRange() const { return mRange; } /* Return digit range */
    bool getSetFlag() const { return set; } /* Return set flag associated
											w/ setCode() */

    /* Overloaded Operators */
    friend ostream& operator << (ostream &out, const code &aCode);
};


