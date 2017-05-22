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
    std::cout << '\n'<< "CSRTuple Array:" << '\n';
    for(int i = 1; i < MAXSIZE && data[i].getColNum()!=0 ; i++)
    {
        std::cout << data[i].getColNum() << '\t';
    }
    std::cout << '\n';
    for(int i = 1; i < MAXSIZE && data[i].getVal()!=0; i++)
    {
        std::cout << data[i].getVal() << '\t';
    }
    std::cout << '\n' << "CSR Row Pointer Array:" << '\n';
    for(unsigned int i = 1; i <= matrixWidth; i++)
    {
        std::cout << rowPtr[i] << '\t';
    }
    std::cout << '\n';
}


//instance modifying
void CSRMatrix::createCSRMatrix(unsigned int matWid, unsigned int matHgt)
{
    matrixWidth = matWid; matrixHeight = matHgt;
    CSRTuple deft; deft.modifyTuple(0,0);
    for(int i = 0; i < MAXSIZE; i++)
    {
        rowPtr[i] = 0;
        data[i] = deft;
    }


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
    unsigned insPos;
    if(rowPtr[rowNum] == 0)
    {
        unsigned int k = rowNum+1;
        while(k <= matrixWidth && rowPtr[k] == 0)
        {
            k++;
        }
        unsigned int insNow = (k > matrixWidth)? 0:  rowPtr[k];
        if(insNow == 0){for(insPos = 1; data[insPos].getColNum()!=0; insPos++);}
        else {for(insPos = 1; insPos < insNow; insPos++);}
        rowPtr[rowNum] = insPos;
    }
    else
    {
        insPos = rowPtr[rowNum];
        if(rowPtr[rowNum+1] == 0)
        {
            while(ins.getColNum() > data[insPos].getColNum()){insPos++;}
        }
        else
        {
            while(ins.getColNum() > data[insPos].getColNum() && insPos < rowPtr[rowNum+1]){insPos++;}
        }
    }
    unsigned int k = 1;
    for(k = 1; data[k].getColNum()!=0; k++);
    unsigned int j;
    for(j = k; j > insPos; j--)
    {
        data[j] = data[j-1];
    }
    data[j] = ins;
    for(unsigned int i = rowNum+1; i <= matrixWidth; i++)
    {
        if(rowPtr[i]!=0)
        {
            rowPtr[i]++;
        }
    }
}


void CSRMatrix::printMatrix() const
{
    unsigned int i = 1;
    while(rowPtr[i]!=0)
    {
        unsigned int colNow = 1;
        for(unsigned int j = rowPtr[i];colNow <= matrixWidth; colNow++)
        {
            if(colNow == data[j].getColNum())
            {
                std::cout << data[j].getVal() << '\t';
                j++;
            }
            else
            {
                std::cout << 0 << '\t';
            }

        }
        std::cout << '\n';
        i++;
    }
}

CSRMatrix::~CSRMatrix()
{
    //dtor
}

}

}
