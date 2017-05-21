#include "MatLib/CSRStore/CSRTuple.h"
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

bool CSRTuple::operator==(const CSRTuple &M) const
{
    if(colNum == M.getColNum() && value == M.getVal())
    {
        return true;
    }
    return false;
}

CSRTuple CSRTuple::operator+(const CSRTuple &T)
{
    if(colNum != T.getColNum())
    {
        std::cout << "ERROR Adding CSRTuples" << '\n';
        return *this;
    }
    CSRTuple Temp;
    Temp.modifyTuple(this->getColNum(), this->getVal() + T.getVal());
    if(Temp.getVal() == 0)
    {
        Temp.modifyTuple(0,0);
    }
    return Temp;


}

CSRTuple CSRTuple::operator-(const CSRTuple &M)
{
    if(colNum != M.getColNum())
    {
        std::cout << "ERROR Sub CSRTuples." << '\n';
        return *this;
    }
    CSRTuple Temp;
    if(this->getVal() == M.getVal())
    {
        Temp.modifyTuple(0,0);
    }
    else
    {
        Temp.modifyTuple(this->getColNum(), this->getVal() - M.getVal());
    }
    return Temp;
}
CSRTuple::~CSRTuple()
{
    //dtor
}
