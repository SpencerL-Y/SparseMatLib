#ifndef CSRTUPLE_H
#define CSRTUPLE_H
#define MAXSIZE 1000
/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: CRSTuple
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/19/2017
 * Last Modified: 5/19/2017
 -----------------------------------------------------------------------------------------------*/

class CSRTuple
{
    public:
        CSRTuple();
        virtual ~CSRTuple();
        void modifyTuple(unsigned int col, int val);
        void destroyTuple();
        void printTuple();
    protected:
        unsigned int colNum;
        int value;
    private:
};

#endif // CSRTUPLE_H
