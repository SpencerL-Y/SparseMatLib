/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: CRSTuple
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 5/19/2017
 * Last Modified: 6/20/2017
 -----------------------------------------------------------------------------------------------*/#ifndef CSRTUPLE_H
#define CSRTUPLE_H
#define MAXSIZE 1000

namespace MatLib
{
namespace CSRStore
{
template <typename T>
class CSRTuple
{
    public:
        CSRTuple();
        virtual ~CSRTuple();
        void modifyTuple(unsigned int col, T val);
        void destroyTuple();
        void printTuple() const;
        unsigned int getColNum() const;
        T getVal() const;
        void operator=(const CSRTuple &t);
        bool operator!=(const CSRTuple &t) const;
        bool operator==(const CSRTuple &t) const;
        CSRTuple operator+(const CSRTuple &t);
        CSRTuple operator-(const CSRTuple &t);
    protected:
        unsigned int colNum;
        T value;
    private:
};

}
}
#endif // CSRTUPLE_H
