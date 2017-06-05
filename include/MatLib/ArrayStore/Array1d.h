/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: Array1d
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 6/5/2017
 * Last Modified: 6/5/2017
 -----------------------------------------------------------------------------------------------*/
#ifndef ARRAY1D_H
#define ARRAY1D_H
#include <vector>
using namespace std;

namespace MatLib
{

namespace ArrayStore
{

class Array1d
{
    public:
        Array1d(unsigned int length);
        Array1d();
        void resizeArray(unsigned arySize, int value);
        void resizeArray(unsigned arySize);
        void setZero();
        void elemAssign(unsigned int pos, int value);

        void arrayPrint() const;
        unsigned int getSize() const;
        int dotProduct(const Array1d &ary) const;

        virtual ~Array1d();

    protected:
        unsigned int arraySize;
        vector<int> vec;

    private:
};

}
}
#endif // ARRAY1D_H
