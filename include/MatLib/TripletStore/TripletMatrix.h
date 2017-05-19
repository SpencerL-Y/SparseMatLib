
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: TripletMatrix
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/12/2017
 * Last Modified: 5/19/2017
 -----------------------------------------------------------------------------------------------*/
#ifndef TRIPLETMATRIX_H
#include "Triplet.h"
#define TRIPLETMATRIX_H


#define MAXSIZE 1000

namespace MatLib
{

namespace TripletStore
{

class TripletMatrix
{
    public:
        TripletMatrix();
        virtual ~TripletMatrix();
        // Instance untouched
        void printMatrix() const;
        void displayTable() const;
        unsigned int getMatrixWidth() const;
        unsigned int getMatrixHeight() const;
        unsigned int getMatrixNonZeroNum() const;
        TripletMatrix getNegMatrix() const;
        // Instance Modifying
        void createMatrix(unsigned int width, unsigned int height, unsigned int nonZero);
        void insertTripletToMatrix(Triplet insertTriplet);

        void destroyMatrix();
        void nonZeroUpdate();
        // Operators Overload
        void operator=(const TripletMatrix &M);
        bool operator==(const TripletMatrix &M) const;
        TripletMatrix operator+(const TripletMatrix &M);
        TripletMatrix operator-(const TripletMatrix &M);
        TripletMatrix operator*(const TripletMatrix &M);

    protected:
        unsigned int matrixWidth; unsigned int matrixHeight;
        unsigned int nonZeroNum;
        Triplet data[MAXSIZE];
    private:
};

}

}

#endif // TRIPLETMATRIX_H
