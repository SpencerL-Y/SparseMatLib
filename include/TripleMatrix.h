
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: Triple
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/12/2017
 * Last Modified: 5/14/2017
 -----------------------------------------------------------------------------------------------*/
#ifndef TRIPLEMATRIX_H
#include "Triple.h"
#define TRIPLEMATRIX_H
//Non-Zero Size defined here
#define MAXSIZE 1000

namespace MatLib
{

namespace TripleStore
{

class TripleMatrix
{
    public:
        TripleMatrix();
        virtual ~TripleMatrix();
        // Instance untouched
        void printMatrix() const;
        void displayTable() const;
        unsigned int getMatrixWidth() const;
        unsigned int getMatrixHeight() const;
        unsigned int getMatrixNonZeroNum() const;
        TripleMatrix getNegMatrix() const;
        // Instance Modifying
        void createMatrix(unsigned int width, unsigned int height, unsigned int nonZero);
        void insertTripleToMatrix(Triple insertTriple);

        void destroyMatrix();
        void nonZeroUpdate();
        // Operators Overload
        void operator=(const TripleMatrix &M);
        bool operator==(const TripleMatrix &M) const;
        TripleMatrix operator+(const TripleMatrix &M);
        TripleMatrix operator-(const TripleMatrix &M);
        TripleMatrix operator*(const TripleMatrix &M);

    protected:
        unsigned int matrixWidth; unsigned int matrixHeight;
        unsigned int nonZeroNum;
        Triple data[MAXSIZE];
    private:
};

}

}
#endif // TRIPLEMATRIX_H
