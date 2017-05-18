#include "CSRTuple.h"
#include <iostream>
CSRTuple::CSRTuple()
{
    //ctor
}

void CSRTuple::modifyTuple(unsigned int col, int val)
{
    colNum = col; value = val;
}

void CSRTuple::printTuple()
{
    if(colNum)
        std::cout<< colNum << '\t' << value << '\n';
}

void CSRTuple::destroyTuple()
{
    colNum = 0; value = 0;
}
CSRTuple::~CSRTuple()
{
    //dtor
}
