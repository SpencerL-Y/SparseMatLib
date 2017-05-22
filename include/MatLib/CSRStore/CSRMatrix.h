#ifndef CSRMATRIX_H
#include "CSRTuple.h"
#define CSRMATRIX_H
#define MAXSIZE 1000
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: CSRMatrix
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/19/2017
 * Last Modified: 5/22/2017
 -----------------------------------------------------------------------------------------------*/
namespace MatLib
{

namespace CSRStore
{


class CSRMatrix
{
    public:
        CSRMatrix();
        virtual ~CSRMatrix();
        void printMatrix() const;
        void displayTable() const;

        unsigned int getMatrixWidth() const;
        unsigned int getMatrixHeight() const;
        unsigned int getMatrixNonZeroNum() const;
        CSRMatrix getNegMat(const CSRMatrix &M) const;
        //instance modifying
        void createCSRMatrix(unsigned int matWid, unsigned int matHgt);
        void insertTupleToMatrix(unsigned int rowNum, CSRTuple ins);
        void destroyMatrix();
        //operator overload
        void operator=(const CSRMatrix &M);
        bool operator==(const CSRMatrix &M) const;
        CSRMatrix operator+(const CSRMatrix &M);
        CSRMatrix operator-(const CSRMatrix &M);
        CSRMatrix operator*(const CSRMatrix &M);
    protected:
        unsigned int matrixWidth; unsigned int matrixHeight;
        unsigned int rowPtr[MAXSIZE];
        CSRTuple data[MAXSIZE];
    private:
};

}

}
#endif // CSRMATRIX_H
