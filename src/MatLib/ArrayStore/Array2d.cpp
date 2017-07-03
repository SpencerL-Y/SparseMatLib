#include "Array2d.h"
namespace MatLib
{
namespace ArrayStore
{
template <typename T>
Array2d<T>::Array2d()
{
    //ctor
}
template <typename T>
Array2d<T>::Array2d(unsigned int wid,\
                    unsigned int hgt)
{
    /* Debugged */
    this->matrixWidth = wid;
    this->matrixHeight = hgt;
    std::vector<T> vec(hgt+1, 0);
    for(unsigned int i = 0; i <= wid; i++)
    {
        data.push_back(vec);
    }
}
template <typename T>
void Array2d<T>::printMatrix() const
{
    /* Debugged */
    std::cout << "Array2d matrix print:" << '\n';
    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        for(unsigned int j = 1; j <= this->getHeight(); j++)
        {
            std::cout << data[i][j] << '\t';
        }
        std::cout << '\n';
    }
}
template <typename T>
unsigned int Array2d<T>::getWidth() const
{
    return this->matrixWidth;
}
template <typename T>
unsigned int Array2d<T>::getHeight() const
{
    return this->matrixHeight;
}
template <typename T>
unsigned int Array2d<T>::getNonZeroNum() const
{
    unsigned int nonZeroCnt = 0;
    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        for(unsigned int j = 1; j <= this->getHeight(); j++)
        {
            if(data[i][j]!=0)
            {
                nonZeroCnt++;
            }
        }
    }
    return nonZeroCnt;
}
template <typename T>
Array2d<T> Array2d<T>::getNegMatrix() const
{
    /* Debugged */
    Array2d<T> Temp(this->getWidth(),\
                 this->getHeight());
    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        for(unsigned int j = 1; j <= this->getHeight(); j++)
        {
            Temp.data[i][j] = -(this->data[i][j]);
        }
    }
    return Temp;
}
template <typename T>
Array2d<T> Array2d<T>::transpose() const
{
    /* Debugged */
    Array2d<T> Temp(this->getHeight(),\
                 this->getWidth());
    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        for(unsigned int j = 1; j <= this->getHeight(); j++)
        {
            Temp.data[j][i] = this->data[i][j];
        }
    }
    return Temp;
}
template <typename T>
void Array2d<T>::insertElem(unsigned int row,\
                            unsigned int col,\
                                  T val)
{
    /* Debugged*/
    this->data[row][col] = val;
    return;
}
template <typename T>
void Array2d<T>::operator=(const Array2d<T> &M)
{
    /* Debugged */
    this->matrixWidth = M.getWidth();
    this->matrixHeight = M.getHeight();
    this->data.clear();
    std::vector<T> vec(this->matrixHeight+1, 0);
    for(unsigned int i = 0; i <= this->matrixWidth; i++)
    {
        this->data.push_back(vec);
    }
    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        for(unsigned int j = 1; j <= this->getHeight(); j++)
        {
            this->data[i][j] = M.data[i][j];
        }
    }
    return ;
}
template <typename T>
Array2d<T> Array2d<T>::operator+(const Array2d<T> &M)
{
    /* Debugged */
    if(this->getWidth()!= M.getWidth() ||\
       this->getHeight() != M.getHeight())
    {
        std::cout << "Error adding Array2d<T> matrix, size incompatible." << '\n';
        return *this;
    }
    Array2d<T> Temp(this->getWidth(),\
                 this->getHeight());
    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        for(unsigned int j = 1; j <= this->getHeight(); j++)
        {
            Temp.data[i][j] = this->data[i][j] + M.data[i][j];
        }
    }
    return Temp;
}
template <typename T>
Array2d<T> Array2d<T>::operator*(const Array2d<T> &M)
{
    /* Debugged */
    if(this->getHeight() != M.getWidth())
    {
        std::cout << "Error Array2d<T> matrix multiplication, size incompatible." << '\n';
        return *this;
    }
    Array2d<T> Temp(this->getWidth(),\
                 M.getHeight());
    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        for(unsigned int j = 1; j <= M.getHeight(); j++)
        {
            int tempSum = 0;
            for(unsigned int k = 1; k <= this->getHeight(); k++)
            {
                tempSum += (this->data[i][k])*(M.data[k][j]);
            }
            Temp.insertElem(i, j, tempSum);
        }
    }
    return Temp;
}
template <typename T>
Array2d<T> Array2d<T>::operator-(const Array2d<T> &M)
{
    /* Debugged */
    Array2d<T> Temp(this->getWidth(),\
                 this->getHeight());
    Temp = *this + M.getNegMatrix();
    return Temp;
}
template <typename T>
Array2d<T>::~Array2d()
{
    //dtor
}

template class Array2d<double>;
template class Array2d<int>;

}//ArrayStore
}//MatLib

