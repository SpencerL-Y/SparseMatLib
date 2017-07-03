
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: TripletMatrix
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/12/2017
 * Last Modified: 6/3/2017
 -----------------------------------------------------------------------------------------------*/
#ifndef TRIPLETMATRIX_H
#define TRIPLETMATRIX_H
#include <iostream>
#include <vector>
#include "MatLib/TripletStore/Triplet.h"



namespace MatLib
{

namespace TripletStore
{
template <typename T>
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
        TripletMatrix transposeMatrix() const;
        // Instance Modifying
        void resizeMatrix(unsigned int width,\
                          unsigned int height, unsigned int nonZero);
        void insertTripletToMatrix(Triplet<T> insertTriplet);
        void nonZeroUpdate();
        // Operators Overload
        void operator=(const TripletMatrix &M);
        bool operator==(const TripletMatrix &M) const;
        TripletMatrix operator+(const TripletMatrix &M);
        TripletMatrix operator-(const TripletMatrix &M);
        TripletMatrix operator*(const TripletMatrix &M);
        std::vector<Triplet<T>> data;
    protected:
        unsigned int matrixWidth; unsigned int matrixHeight;
        unsigned int nonZeroNum;

    private:
};

}

}

#endif // TRIPLETMATRIX_H
