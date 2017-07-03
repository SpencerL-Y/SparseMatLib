

#include "MatLib/TripletStore/Triplet.h"
namespace MatLib
{

namespace TripletStore
{
template <typename T>
Triplet<T>::Triplet()
{
    rowNum = 0; colNum = 0;
    value = 0;//ctor
}
template <typename T>
unsigned int Triplet<T>::getRowNum() const
{
    return rowNum;
}
template <typename T>
unsigned int Triplet<T>::getColNum() const
{
    return colNum;
}
template <typename T>
void Triplet<T>::displayTriplet() const
{
    //std::cout << "Triplet Print:" << '\n';
    std::cout << rowNum <<'\t'<< colNum << '\t' << value << '\n';
}
template <typename T>
T Triplet<T>::getValue() const
{
    return value;
}
template <typename T>
void Triplet<T>::modifyTriplet(unsigned int newRow, unsigned int newCol, T newVal)
{
    rowNum = newRow; colNum = newCol;
    value = newVal;
}



//Operators Overload
template <typename T>
void Triplet<T>::operator=(const Triplet<T> &t)
{
    rowNum = t.getRowNum();
    colNum = t.getColNum();
    value = t.getValue();
}
template <typename T>
bool Triplet<T>::operator==(const Triplet<T> &t) const
{
    if(rowNum == t.getRowNum() && colNum == t.getColNum() && value == t.getValue())
    {
        return true;
    }
    else return false;
}
template <typename T>
Triplet<T> Triplet<T>::operator+(const Triplet<T> &t)
{
    if(this->getRowNum() != t.getRowNum() || this->getColNum() != t.getColNum())
    {
        std::cout << "ERROR: Unable to add Triple" << '\n';
        return *this;
    }
    Triplet<T> Temp;
    Temp.rowNum = this->getRowNum(); Temp.colNum = this->getColNum();
    Temp.value = this->getValue() + t.getValue();
    if(Temp.getValue() == 0)
    {
        Temp.modifyTriplet(0,0,0);
    }
    return Temp;
}



template <typename T>
Triplet<T>::~Triplet()
{
    //dtor
}

template class Triplet<double>;
template class Triplet<int>;

}

}
