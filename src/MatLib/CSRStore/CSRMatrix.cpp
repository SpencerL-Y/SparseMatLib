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



void CSRMatrix::printMatrix() const
{

}

CSRMatrix::~CSRMatrix()
{
    //dtor
}

}

}
