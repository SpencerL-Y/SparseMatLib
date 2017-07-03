
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

template <typename T>
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
        T getValue() const;
        void displayTriplet() const;

        void modifyTriplet(unsigned int newRow,\
                           unsigned int newCol, T newVal);
        void operator=(const Triplet &t);
        bool operator==(const Triplet &t) const;
        Triplet operator+(const Triplet &t);
        Triplet operator-(const Triplet &t);
    protected:
        unsigned int rowNum;
        unsigned int colNum;
        T value;
    private:
};


}

}
#endif // TRIPLET_H
