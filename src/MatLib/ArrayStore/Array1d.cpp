#include "MatLib/ArrayStore/Array1d.h"
#include <iostream>

namespace MatLib
{

namespace ArrayStore
{



Array1d::Array1d(unsigned int length)
{
    this->arraySize = length;
    vec.push_back(0);
    vec.resize(length+1, 0);
    return;
}
Array1d::~Array1d()
{
    this->arraySize = 0; vec.push_back(0);
    //dtor
}


void Array1d::resizeArray(unsigned int arySize, int value)
{
    // vector resize
    this->arraySize = arySize;
    vec.resize(arySize+1, value);
}
void Array1d::resizeArray(unsigned int arySize)
{
    // vector resize
    vec.resize(arySize+1, 0);
    this->arraySize = arySize;
}
void Array1d::setZero()
{
    //set all element int vec to 0
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        vec[i] = 0;
    }
}
void Array1d::elemAssign(unsigned int pos, int value)
{
    /* TODO: assign the value to vec[pos] if pos < size
     * Debugged
     */
    if(pos > this->arraySize|| pos == 0)
    {
        std::cout << "ERROR in array1d assignment" <<'\n';
        return;
    }
    this->vec[pos] = value; return;
}

unsigned int  Array1d::getSize() const
{
    return arraySize;
}

void Array1d::arrayPrint() const
{
    /* TODO: print array in sequence
     * Debugged
     */
    std::cout << "Array1d print: " << '\n';
    for(unsigned int i = 1; i < this->vec.size(); i++)
    {
        std::cout << this->vec[i] << '\n';
    }
    return;
}

int Array1d::dotProduct(const Array1d &ary) const
{
    /* TODO: dotProduct
     * Debugged
     */
    if(vec.size() != ary.vec.size())
    {
        std::cout << "ERROR in dotProduct" << '\n';
        return 0;
    }
    int sum = 0;
    for(unsigned int i = 1; i < vec.size(); i++)
    {
        sum += (vec[i])*(ary.vec[i]);
    }
    return sum;
}




}

}
