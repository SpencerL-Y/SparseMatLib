#include "Triple.h"
#include <iostream>

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

unsigned int Triple::getRowNum()
{
    return rowNum;
}

unsigned int Triple::getColNum()
{
    return colNum;
}

void Triple::displayTriple()
{
    //std::cout << "Triple Print:" << '\n';
    std::cout << rowNum <<'\t'<< colNum << '\t' << value << '\n';
}

int Triple::getValue()
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
//destructor
Triple::~Triple()
{
    //dtor
}

}//End Namespace Triple

}//End Namespace MatLib
