#ifndef CRSMATRIX_H
#include "CSRTuple.h"
#define CRSMATRIX_H
#define MAXSIZE 1000
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: CRSMatrix
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/19/2017
 * Last Modified: 5/19/2017
 -----------------------------------------------------------------------------------------------*/
namespace MatLib
{

namespace CSRStore
{


class CRSMatrix
{
    public:
        CRSMatrix();
        virtual ~CRSMatrix();
        void printMatrix() const;
        void displayTable() const;

        unsigned int getMatrixWidth() const;
        unsigned int getMatrixHeight() const;
        unsigned int getMatrixNonZeroNum() const;
        CRSMatrix getNegMat(const CRSMatrix &M) const;
        //instance modifying
        void insertTupleToMatrix(unsigned int rowNum);
        void destroyMatrix();
        //operator overload
        void operator=(const CRSMatrix &M);
        bool operator==(const CRSMatrix &M) const;
        CRSMatrix operator+(const CRSMatrix &M);
        CRSMatrix operator-(const CRSMatrix &M);
        CRSMatrix operator*(const CRSMatrix &M);
    protected:
        unsigned int rowPtr[MAXSIZE];
        CSRTuple data[MAXSIZE];
    private:
};

}

}
#endif // CRSMATRIX_H
