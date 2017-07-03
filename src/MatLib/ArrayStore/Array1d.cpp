#include "MatLib/ArrayStore/Array1d.h"


namespace MatLib
{
namespace ArrayStore
{
template <typename T>
Array1d<T>::Array1d(unsigned int length, bool rowVector)
{
    this->rowVec = rowVector;
    this->arraySize = length;
    vec.push_back(0);
    vec.resize(length+1, 0);
    return;
}
template <typename T>
Array1d<T>::~Array1d()
{
    this->rowVec = 1;
    this->arraySize = 0; vec.push_back(0);
    //dtor
}
template <typename T>
void Array1d<T>::resizeArray(unsigned int arySize, T value)
{
    // vector resize
    this->arraySize = arySize;
    vec.resize(arySize+1, value);
}
template <typename T>
void Array1d<T>::resizeArray(unsigned int arySize)
{
    // vector resize
    vec.resize(arySize+1, 0);
    this->arraySize = arySize;
}
template <typename T>
void Array1d<T>::setZero()
{
    //set all element int vec to 0
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        vec[i] = 0;
    }
}
template <typename T>
void Array1d<T>::elemAssign(unsigned int pos, T value)
{
    /* TODO: assign the value to vec[pos] if pos < size
     * Debugged
     */
    if(pos > this->arraySize|| pos == 0)
    {
        std::cout << "ERROR in Array1d assignment" <<'\n';
        return;
    }
    this->vec[pos] = value; return;
}
template <typename T>
void Array1d<T>::transpose()
{
    this->rowVec = !(this->rowVec);
}
template <typename T>
unsigned int Array1d<T>::getSize() const
{
    return arraySize;
}
template <typename T>
void Array1d<T>::arrayPrint() const
{
    /* TODO: print array in sequence
     * Debugged
     */
    std::cout << "Array1d print: " << '\n';
    if(!(this->rowVec))
    {
        for(unsigned int i = 1; i < this->vec.size(); i++)
        {
            std::cout << this->vec[i] << '\n';
        }
    }
    else
    {
        for(unsigned int i = 1; i < this->vec.size();i++)
        {
            std::cout << this->vec[i] << '\t';
        }
        std::cout << '\n';
    }
    return;
}
template <typename T>
T Array1d<T>::dotProduct(const Array1d<T> &ary) const
{
    /* TODO: dotProduct
     * Debugged
     */
    if(vec.size() != ary.vec.size())
    {
        std::cout << "ERROR in dotProduct" << '\n';
        return 0;
    }
    T sum = 0;
    for(unsigned int i = 1; i < vec.size(); i++)
    {
        sum += (vec[i])*(ary.vec[i]);
    }
    return sum;
}
template <typename T>
Array1d<T> Array1d<T>::operator+(const Array1d<T> &A)
{
    if(this->arraySize != A.arraySize)
    {
        std::cout << "ERROR: Array1d<T> add error, size incompatible." <<'\n';
    }
    Array1d<T> temp(this->arraySize, 1);
    for(unsigned int i = 0; i < this->vec.size(); i++)
    {
        temp.vec[i] = (this->vec[i]+\
                       A.vec[i]);
    }
    return temp;
}

template class Array1d<double>;
template class Array1d<int>;

}//ArrayStore
}//MatLib
