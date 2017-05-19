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

void CSRTuple::printTuple() const
{
    if(colNum)
        std::cout<< colNum << '\t' << value << '\n';
}

void CSRTuple::destroyTuple()
{
    colNum = 0; value = 0;
}

unsigned int CSRTuple::getColNum() const
{
    return colNum;
}

int CSRTuple::getVal() const
{
    return value;
}

void CSRTuple::operator=(const CSRTuple &T)
{
    colNum = T.getColNum(); value = T.getVal();
}


CSRTuple::~CSRTuple()
{
    //dtor
}
