

#include "MatLib/TripletStore/Triplet.h"
namespace MatLib
{

namespace TripletStore
{

Triplet::Triplet()
{
    rowNum = 0; colNum = 0;
    value = 0;//ctor
}

unsigned int Triplet::getRowNum() const
{
    return rowNum;
}

unsigned int Triplet::getColNum() const
{
    return colNum;
}

void Triplet::displayTriplet() const
{
    //std::cout << "Triple Print:" << '\n';
    std::cout << rowNum <<'\t'<< colNum << '\t' << value << '\n';
}

int Triplet::getValue() const
{
    return value;
}

void Triplet::modifyTriplet(unsigned int newRow, unsigned int newCol, int newVal)
{
    rowNum = newRow; colNum = newCol;
    value = newVal;
}



//Operators Overload
void Triplet::operator=(const Triplet &T)
{
    rowNum = T.getRowNum();
    colNum = T.getColNum();
    value = T.getValue();
}

bool Triplet::operator==(const Triplet &T) const
{
    if(rowNum == T.getRowNum() && colNum == T.getColNum() && value == T.getValue())
    {
        return true;
    }
    else return false;
}

Triplet Triplet::operator+(const Triplet &T)
{
    if(this->getRowNum() != T.getRowNum() || this->getColNum() != T.getColNum())
    {
        std::cout << "ERROR: Unable to add Triple" << '\n';
        return *this;
    }
    Triplet Temp;
    Temp.rowNum = this->getRowNum(); Temp.colNum = this->getColNum();
    Temp.value = this->getValue() + T.getValue();
    if(Temp.getValue() == 0)
    {
        Temp.modifyTriplet(0,0,0);
    }
    return Temp;
}




Triplet::~Triplet()
{
    //dtor
}

}

}
