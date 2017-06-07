
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: Triplet
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/12/2017
 * Last Modified: 6/3/2017
 -----------------------------------------------------------------------------------------------*/

#ifndef TRIPLET_H
#define TRIPLET_H
#include <iostream>


namespace MatLib
{

namespace TripletStore
{


class Triplet
{
    public:
        Triplet();
        /* ATTENTION:
         * row number of first row is 1
         * 0 means the end of the list.
         */
        virtual ~Triplet();
        // Methods that do no change to instance: add const qualifier.
        unsigned int getRowNum() const;
        unsigned int getColNum() const;
        int getValue() const;
        void displayTriplet() const;

        void modifyTriplet(unsigned int newRow, unsigned int newCol, int newVal);
        void operator=(const Triplet &T);
        bool operator==(const Triplet &T) const;
        Triplet operator+(const Triplet &T);
        Triplet operator-(const Triplet &T);
    protected:
        unsigned int rowNum;
        unsigned int colNum;
        int value;
    private:
};


}

}
#endif // TRIPLET_H
