/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: RowLinkTriMat
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 6/4/2017
 * Last Modified: 6/6/2017
 -----------------------------------------------------------------------------------------------*/
#ifndef ROWLINKTRIMAT_H
#define ROWLINKTRIMAT_H

#include <MatLib/TripletStore/TripletMatrix.h>
using namespace std;


namespace MatLib
{

namespace TripletStore
{



class RowLinkTriMat : public TripletMatrix
{
    public:
        RowLinkTriMat();
        virtual ~RowLinkTriMat();
        void resizeMatrix(unsigned int width, unsigned int height, unsigned int nonZero);
        void insertTripletToMatrix(Triplet insertTriplet);


        void displayTable() const;
        void operator=(const RowLinkTriMat &M);
        RowLinkTriMat operator+(const RowLinkTriMat &M);
        RowLinkTriMat operator*(const RowLinkTriMat &M);


    protected:
        vector<unsigned int> rowPtr;
    private:
};




}


}
#endif // ROWLINKTRIMAT_H
