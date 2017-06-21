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


class CSRMatrix
{
    public:
        CSRMatrix(unsigned int width, unsigned int height);
        virtual ~CSRMatrix();
        void printMatrix() const;
        void displayTable() const;

        unsigned int getMatrixWidth() const;
        unsigned int getMatrixHeight() const;
        unsigned int getMatrixNonZeroNum() const;
        CSRMatrix getNegMat() const;
        //instance modifying
        void clearCSRMatrix(unsigned int matWid, unsigned int matHgt);
        void insertTupleToMatrix(unsigned int rowNum, CSRTuple ins);
        void insertElemToMat(unsigned int rowNum, unsigned int colNum, int value);
        void addInsert(unsigned int rowNum, CSRTuple ins);
        //operator overload
        void operator=(const CSRMatrix &M);
        bool operator==(const CSRMatrix &M) const;
        CSRMatrix operator+(const CSRMatrix &M);
        CSRMatrix operator-(const CSRMatrix &M);
        CSRMatrix operator*(const CSRMatrix &M);
    protected:
        unsigned int matrixWidth; unsigned int matrixHeight;
        std::vector<int>rowPtr;
        std::vector<CSRTuple> data;
    private:
};

}

}
#endif // CSRMATRIX_H
