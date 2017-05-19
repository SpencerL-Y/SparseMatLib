#include "MatLib/CSRStore/CSRMatrix.h"
#include <iostream>

namespace MatLib
{

namespace CSRStore
{


CSRMatrix::CSRMatrix()
{
    //ctor
}

void CSRMatrix::displayTable() const
{
    std::cout << "CSRTuple Array:" << '\n';
    for(int i = 0; i < MAXSIZE && data[i].getColNum()!=0 ; i++)
    {
        std::cout << data[i].getColNum() << '\t';
    }
    std::cout << '\n';
    for(int i = 0; i < MAXSIZE && data[i].getVal()!=0; i++)
    {
        std::cout << data[i].getVal() << '\t';
    }
    std::cout << '\n' << "CSR Row Pointer Array" << '\n';
    for(int i = 0; i< MAXSIZE && rowPtr[i]!=0; i++)
    {
        std::cout << rowPtr[i] << '\t';
    }
}


//instance modifying
void CSRMatrix::createCSRMatrix(unsigned int matWid, unsigned int matHgt)
{
    matrixWidth = matWid; matrixHeight = matHgt;
}

unsigned int CSRMatrix::getMatrixWidth() const
{
    return matrixWidth;
}

unsigned int CSRMatrix::getMatrixHeight() const
{
    return matrixHeight;
}

unsigned int CSRMatrix::getMatrixNonZeroNum() const
{
    unsigned int i;
    for(i = 0; i< MAXSIZE && data[i].getColNum()!=0; i++)
    {
        ;
    }
    return i+1;
}

void CSRMatrix::insertTupleToMatrix(unsigned int rowNum, CSRTuple ins)
{
    int i = rowPtr[rowNum - 1];
    int j = (rowPtr[rowNum]==0)? MAXSIZE: rowPtr[rowNum];
    int k;
    for(k = i; k < j; k++)
    {
        if(data[k].getColNum() < ins.getColNum())
        {
            break;
        }
    }
    int w;
    for(w = getMatrixNonZeroNum(); w>=k; w--)
    {
        data[w] = data[w-1];
    }


}


void CSRMatrix::printMatrix() const
{

}

CSRMatrix::~CSRMatrix()
{
    //dtor
}

}

}
