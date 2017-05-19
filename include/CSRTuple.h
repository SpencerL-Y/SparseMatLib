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
        void printTuple() const;
        unsigned int getColNum() const;
        int getVal() const;
        void operator=(const CSRTuple &T);
        bool operator==(const CSRTuple &T) const;
        CSRTuple operator+(const CSRTuple &T);
        CSRTuple operator-(const CSRTuple &T);
    protected:
        unsigned int colNum;
        int value;
    private:
};

#endif // CSRTUPLE_H
