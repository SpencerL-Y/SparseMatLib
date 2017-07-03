
#include <iostream>
#include "MatLib/CSRStore/CSRTuple.h"
namespace MatLib
{

namespace CSRStore
{


template <typename T>
CSRTuple<T>::CSRTuple()
{
    //ctor
}
template <typename T>
void CSRTuple<T>::modifyTuple(unsigned int col, T val)
{
    colNum = col; value = val;
}
template <typename T>
void CSRTuple<T>::printTuple() const
{
    if(colNum)
        std::cout<< colNum << '\t' \
                 << value  << '\n';
}
template <typename T>
void CSRTuple<T>::destroyTuple()
{
    colNum = 0; value = 0;
}
template <typename T>
unsigned int CSRTuple<T>::getColNum() const
{
    return colNum;
}
template <typename T>
T CSRTuple<T>::getVal() const
{
    return value;
}
template <typename T>
void CSRTuple<T>::operator=(const CSRTuple<T> &t)
{
    colNum = t.getColNum(); value = t.getVal();
}
template <typename T>
bool CSRTuple<T>::operator==(const CSRTuple<T> &t) const
{
    if(colNum == t.getColNum() && value == t.getVal())
    {
        return true;
    }
    return false;
}
template <typename T>
CSRTuple<T> CSRTuple<T>::operator+(const CSRTuple<T> &t)
{
    if(colNum != t.getColNum())
    {
        std::cout << "ERROR Adding CSRTuples" << '\n';
        return *this;
    }
    CSRTuple<T> Temp;
    Temp.modifyTuple(this->getColNum(), \
                     this->getVal() + t.getVal());
    if(Temp.getVal() == 0)
    {
        Temp.modifyTuple(0,0);
    }
    return Temp;


}
template <typename T>
bool CSRTuple<T>::operator!=(const CSRTuple<T> &t) const
{
    if(this->colNum != t.getColNum() ||\
       this->value  != t.getVal())
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
CSRTuple<T> CSRTuple<T>::operator-(const CSRTuple<T> &t)
{
    if(colNum != t.getColNum())
    {
        std::cout << "ERROR Sub CSRTuples." << '\n';
        return *this;
    }
    CSRTuple<T> Temp;
    if(this->getVal() == t.getVal())
    {
        Temp.modifyTuple(0,0);
    }
    else
    {
        Temp.modifyTuple(this->getColNum(),\
                         this->getVal() - t.getVal());
    }
    return Temp;
}
template <typename T>
CSRTuple<T>::~CSRTuple<T>()
{
    //dtor
}

template class CSRTuple<double>;
template class CSRTuple<int>;
}//CSRStore
}//MatLib
