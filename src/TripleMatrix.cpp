#include "TripleMatrix.h"
#include "Triple.h"
#include <iostream>

namespace MatLib
{

namespace TripleStore
{

//constructor
//li
TripleMatrix::TripleMatrix()
{
    matrixWidth = 0; matrixHeight = 0;
    nonZeroNum = 0;
    //std::cout<< "TripleMatrix Constructed!" << '\n';
}


void TripleMatrix::createMatrix(unsigned int width, unsigned int height, unsigned int nonZero)
{
    matrixWidth = width; matrixHeight = height;
    nonZeroNum = nonZero;
}

void TripleMatrix::destroyMatrix()
{
    matrixWidth = 0; matrixHeight = 0;
    nonZeroNum = 0;
    for(int i = 0; i < MAXSIZE && data[i].getRowNum()!= 0; i++)
    {
       data[i].setZero();
    }
}

void TripleMatrix::insertTripleToMatrix(Triple insertTriple)
{
    /* TODO: Insert a Triple into the right place of matrix table
     * if the position is not 0, return ERROR
     */
    int i, j;
    for(i = 0; i < MAXSIZE && data[i].getRowNum()!= 0 &&
    ((data[i].getRowNum() < insertTriple.getRowNum())|| (data[i].getRowNum() == insertTriple.getRowNum() && data[i].getColNum() <= insertTriple.getColNum()))\
    ; i++)
    {
        if((data[i].getRowNum() == insertTriple.getRowNum() && data[i].getColNum() == insertTriple.getColNum()))
        {
            std::cout << "Element Exists. Insert Failed."<< '\n';
            return;
        }

    }
    while(data[j].getRowNum()!=0) {j++;}
    for(; j> i; j--)
    {
        data[j] = data[j-1];
    }

    data[j] = insertTriple;
    nonZeroUpdate();
}

void TripleMatrix::nonZeroUpdate()
{
    unsigned int i;
    for(i = 0; i < MAXSIZE && data[i].getRowNum()!=0 ;i++){;}
    nonZeroNum = i;
}

void TripleMatrix::displayTable() const
{
    /*
     * TODO: Display triple table of a matrix
     */
    int i;
    std::cout << "Matrix Table Print:" << '\n';
    for(i = 0; i<MAXSIZE && data[i].getRowNum()!= 0; i++)
    {
        data[i].displayTriple();
    }
}

void TripleMatrix::printMatrix() const
{
    /*
     * TODO: Print matrix.
     */
    unsigned int i, j, k, flag;
    k = 0;
    std::cout << "Matrix Print:" << '\n';
    for(i = 0; i < matrixWidth; i++)
    {
        for(j = 0; j < matrixHeight; j++)
        {
            for(k = 0; k < MAXSIZE && data[k].getRowNum()!=0; k++)
            {
                flag = 0;
                if(data[k].getRowNum() == i+1 && data[k].getColNum() == j+1 )
                {
                    std::cout << data[k].getValue(); flag = 1;
                    break;
                }
            }
            if(flag == 0) {std::cout << 0;} else {;}
            std::cout << '\t';
        }
        std::cout << '\n';
    }

}

unsigned int TripleMatrix::getMatrixWidth() const
{
    return matrixWidth;
}
unsigned int TripleMatrix::getMatrixHeight() const
{
    return matrixHeight;
}
unsigned int TripleMatrix::getMatrixNonZeroNum() const
{
    return nonZeroNum;
}


// Operators Overload

void TripleMatrix::operator=(const TripleMatrix &M)
{
    matrixWidth = M.getMatrixWidth(); matrixHeight = M.getMatrixHeight();
    nonZeroNum = M.getMatrixNonZeroNum();
    int i;
    for( i = 0; i < MAXSIZE && M.data[i].getRowNum(); i++)
    {
        data[i] = M.data[i];
    }
    while(data[i].getRowNum()!=0)
    {
        data[i].modifyTriple(0,0,0);
    }

}

bool TripleMatrix::operator==(const TripleMatrix &M) const
{
    if((matrixHeight == M.getMatrixHeight()) && (matrixWidth == M.getMatrixWidth())){;}
    else return false;
    int i;
    for(i = 0; i<MAXSIZE && (data[i].getRowNum() || M.data[i].getRowNum()); i++)
    {
        if(!(data[i] == M.data[i]))
        {
            return false;
        }
    }
    return true;
    //lixie
}

TripleMatrix TripleMatrix::operator+(const TripleMatrix &M)
{
    if(this->matrixWidth != M.matrixWidth || this->matrixHeight != M.matrixHeight)
    {
        std::cout << "Unable To Add" << '\n';
        return *this;
    }
    TripleMatrix Temp; Temp.createMatrix(this->matrixWidth, this->matrixHeight, 0);
    unsigned int i = 0;  unsigned int j = 0; unsigned int k = 0;
    while((this->data[i].getRowNum()!=0) && (M.data[j].getRowNum()!=0))
    {
        if(this->data[i].getRowNum() < M.data[j].getRowNum())
        {
            Temp.data[k] = this->data[i];
            i++; k++;
        }
        else if(this->data[i].getRowNum() == M.data[j].getRowNum())
        {
            if(this->data[i].getColNum() < M.data[j].getColNum() )
            {
                Temp.data[k] = this->data[i];
                i++; k++;
            }
            else if(this->data[i].getColNum() == M.data[j].getColNum())
            {
                if(this->data[i].getValue()+M.data[j].getValue() != 0)
                {
                    Temp.data[k] = this->data[i] + M.data[j];
                    k++;
                }
                i++; j++;
            }
            else if(this->data[i].getColNum() > M.data[j].getColNum())
            {
                Temp.data[k] = M.data[j];
                j++; k++;
            }
            else {std::cout << "ERROR" << '\n';}
        }
        else if(this->data[i].getRowNum() > M.data[j].getRowNum())
        {
            Temp.data[k] = M.data[j];
            j++; k++;
        }
        else {std::cout << "ERROR" << '\n';}

    }
    while((this->data[i].getRowNum()!=0) && i<MAXSIZE)
    {
        Temp.data[k] = this->data[i];
        i++; k++;
    }
    while(M.data[j].getRowNum()!=0 && j<MAXSIZE)
    {

        Temp.data[k] = M.data[j];
        j++; k++;
    }
    Temp.nonZeroUpdate();
    return Temp;

}

TripleMatrix TripleMatrix::operator-(const TripleMatrix &M)
{
    if(this->getMatrixWidth() != M.getMatrixWidth() || this->getMatrixHeight() != M.getMatrixHeight())
    {
        std::cout << "ERROR: Unable to Sub" << '\n';
        return *this;
    }
    TripleMatrix Temp;
    Temp.createMatrix(this->getMatrixWidth(), this->getMatrixHeight(), 0);
    unsigned int i; unsigned int j; unsigned int k;

    return *this;
}
//destructor
//xie
TripleMatrix::~TripleMatrix()
{
    //std::cout << "TripleMatrix Destructed." << '\n';
}

}//End Namespace Triple

}//End Namespace MatLib
