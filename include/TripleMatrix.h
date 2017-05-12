
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: Triple
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/12/2017
 * Last Modified: 5/12/2017
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
        void createMatrix(unsigned int width, unsigned int height, unsigned int nonZero);
        void destroyMatrix();
        void insertTripleToMatrix(Triple insertTriple);
        void printMatrix();
        void displayTable();
    protected:
        unsigned int matrixWidth; unsigned int matrixHeight;
        unsigned int nonZeroNum;
        Triple data[MAXSIZE];
    private:
};

}

}
#endif // TRIPLEMATRIX_H
