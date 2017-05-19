
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: Triplet
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/12/2017
 * Last Modified: 5/14/2017
 -----------------------------------------------------------------------------------------------*/


#ifndef TRIPLE_H
#define TRIPLE_H

namespace MatLib
{

namespace TripleStore
{


class Triple
{
    public:
        Triple();
        /* ATTENTION:
         * row number of first row is 1
         * 0 means the end of the list.
         */
        virtual ~Triple();
        // Methods that do no change to instance: add const qualifier.
        unsigned int getRowNum() const;
        unsigned int getColNum() const;
        int getValue() const;
        void displayTriple() const;

        void modifyTriple(unsigned int newRow, unsigned int newCol, int newVal);
        void setZero();
        void operator=(const Triple &T);
        bool operator==(const Triple &T) const;
        Triple operator+(const Triple &T);
        Triple operator-(const Triple &T);
    protected:
        unsigned int rowNum;
        unsigned int colNum;
        int value;
    private:
};


}

}
#endif // TRIPLE_H
