#include "TripleMatrix.h"
#include "Triple.h"
#include <iostream>

namespace MatLib
{

namespace TripleStore
{

//constructor
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
}


void TripleMatrix::displayTable()
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

void TripleMatrix::printMatrix()
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
//destructor
TripleMatrix::~TripleMatrix()
{
    //std::cout << "TripleMatrix Destructed." << '\n';
}

}//End Namespace Triple

}//End Namespace MatLib
