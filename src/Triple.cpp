#include "Triple.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
namespace MatLib
{

namespace TripleStore
{

//constructor
Triple::Triple()
{
    rowNum = 0; colNum = 0;
    value = 0;
}

unsigned int Triple::getRowNum() const
{
    return rowNum;
}

unsigned int Triple::getColNum() const
{
    return colNum;
}

void Triple::displayTriple() const
{
    //std::cout << "Triple Print:" << '\n';
    std::cout << rowNum <<'\t'<< colNum << '\t' << value << '\n';
}

int Triple::getValue() const
{
    return value;
}

void Triple::modifyTriple(unsigned int newRow, unsigned int newCol, int newVal)
{
    rowNum = newRow; colNum = newCol;
    value = newVal;
}

void Triple::setZero()
{
    rowNum = 0; colNum = 0;
    value = 0;
}


//Operators Overload
void Triple::operator=(const Triple &T)
{
    rowNum = T.getRowNum();
    colNum = T.getColNum();
    value = T.getValue();
}

bool Triple::operator==(const Triple &T) const
{
    if(rowNum == T.getRowNum() && colNum == T.getColNum() && value == T.getValue())
    {
        return true;
    }
    else return false;
}

Triple Triple::operator+(const Triple &T)
{
    if(this->getRowNum() != T.getRowNum() || this->getColNum() != T.getColNum())
    {
        std::cout << "ERROR: Unable to add" << '\n';
        return *this;
    }
    Triple Temp;
    Temp.rowNum = this->getRowNum(); Temp.colNum = this->getColNum();
    Temp.value = this->getValue() + T.getValue();
    return Temp;
}

//destructor
Triple::~Triple()
{
    //dtor
}

}//End Namespace Triple

}//End Namespace MatLib
