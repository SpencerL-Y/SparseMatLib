/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: Array1d
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 6/5/2017
 * Last Modified: 6/14/2017
 -----------------------------------------------------------------------------------------------*/
#ifndef ARRAY1D_H
#define ARRAY1D_H
#include <iostream>
#include <vector>


namespace MatLib
{

namespace ArrayStore
{
template <typename T>
class Array1d
{
    public:
        Array1d(unsigned int length, bool rowVector);
        Array1d();
        void resizeArray(unsigned arySize, T value);
        void resizeArray(unsigned arySize);
        void setZero();
        void elemAssign(unsigned int pos, T value);
        void transpose();
        void arrayPrint() const;
        unsigned int getSize() const;
        T dotProduct(const Array1d<T> &ary) const;

        Array1d operator+(const Array1d<T> &A);
        virtual ~Array1d();
        std::vector<T> vec;
    protected:
        bool rowVec;
        unsigned int arraySize;


    private:
};

}
}
#endif // ARRAY1D_H
