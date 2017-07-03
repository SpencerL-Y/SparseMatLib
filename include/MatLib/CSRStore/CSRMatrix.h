/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: CSRMatrix
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/19/2017
 * Last Modified: 6/20/2017
 -----------------------------------------------------------------------------------------------*/
#ifndef CSRMATRIX_H
#define CSRMATRIX_H
#define MAXSIZE 1000
#include <iostream>
#include <vector>
#include "CSRTuple.h"
namespace MatLib
{
namespace CSRStore
{

template <typename T>
class CSRMatrix
{
    public:
        CSRMatrix(unsigned int width, \
                  unsigned int height);
        virtual ~CSRMatrix();
        void printMatrix() const;
        void displayTable() const;

        unsigned int getMatrixWidth() const;
        unsigned int getMatrixHeight() const;
        unsigned int getMatrixNonZeroNum() const;
        CSRMatrix getNegMat() const;
        //instance modifying
        void clearCSRMatrix(unsigned int matWid,\
                            unsigned int matHgt);
        void insertTupleToMatrix(unsigned int rowNum,\
                                 CSRTuple<T> ins);
        void insertElemToMat(unsigned int rowNum,\
                             unsigned int colNum, T value);
        void addInsert(unsigned int rowNum,\
                       CSRTuple<T> ins);
        //operator overload
        void operator=(const CSRMatrix<T> &M);
        bool operator==(const CSRMatrix<T> &M) const;
        CSRMatrix operator+(const CSRMatrix<T> &M);
        CSRMatrix operator-(const CSRMatrix<T> &M);
        CSRMatrix operator*(const CSRMatrix<T> &M);
    protected:
        unsigned int matrixWidth;
        unsigned int matrixHeight;
        std::vector<int>rowPtr;
        std::vector<CSRTuple<T>> data;
    private:
};

}

}
#endif // CSRMATRIX_H
