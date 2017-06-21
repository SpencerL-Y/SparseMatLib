#include "Array2d.h"
namespace MatLib
{
namespace ArrayStore
{

Array2d::Array2d()
{
    //ctor
}

Array2d::Array2d(unsigned int wid,\
                 unsigned int hgt)
{
    /* Debugged */
    this->matrixWidth = wid;
    this->matrixHeight = hgt;
    std::vector<int> vec(hgt+1, 0);
    for(unsigned int i = 0; i <= wid; i++)
    {
        data.push_back(vec);
    }
}

void Array2d::printMatrix() const
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

unsigned int Array2d::getWidth() const
{
    return this->matrixWidth;
}

unsigned int Array2d::getHeight() const
{
    return this->matrixHeight;
}

unsigned int Array2d::getNonZeroNum() const
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

Array2d Array2d::getNegMatrix() const
{
    /* Debugged */
    Array2d Temp(this->getWidth(),\
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

Array2d Array2d::transpose() const
{
    /* Debugged */
    Array2d Temp(this->getHeight(),\
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

void Array2d::insertElem(unsigned int row,\
                         unsigned int col,\
                                  int val)
{
    /* Debugged*/
    this->data[row][col] = val;
    return;
}

void Array2d::operator=(const Array2d &M)
{
    /* Debugged */
    this->matrixWidth = M.getWidth();
    this->matrixHeight = M.getHeight();
    this->data.clear();
    std::vector<int> vec(this->matrixHeight+1, 0);
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

Array2d Array2d::operator+(const Array2d &M)
{
    /* Debugged */
    if(this->getWidth()!= M.getWidth() ||\
       this->getHeight() != M.getHeight())
    {
        std::cout << "Error adding Array2d matrix, size incompatible." << '\n';
        return *this;
    }
    Array2d Temp(this->getWidth(),\
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

Array2d Array2d::operator*(const Array2d &M)
{
    /* Debugged */
    if(this->getHeight() != M.getWidth())
    {
        std::cout << "Error Array2d matrix multiplication, size incompatible." << '\n';
        return *this;
    }
    Array2d Temp(this->getWidth(),\
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

Array2d Array2d::operator-(const Array2d &M)
{
    /* Debugged */
    Array2d Temp(this->getWidth(),\
                 this->getHeight());
    Temp = *this + M.getNegMatrix();
    return Temp;
}

Array2d::~Array2d()
{
    //dtor
}

}//ArrayStore
}//MatLib

