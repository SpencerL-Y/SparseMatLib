
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: Triple
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/12/2017
 * Last Modified: 5/12/2017
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
        unsigned int getRowNum();
        unsigned int getColNum();
        int getValue();

        void displayTriple();
        void modifyTriple(unsigned int newRow, unsigned int newCol, int newVal);
        void setZero();
    protected:
        unsigned int rowNum;
        unsigned int colNum;
        int value;
    private:
};


}

}
#endif // TRIPLE_H
