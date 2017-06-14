/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: Array2d
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 6/14/2017
 * Last Modified: 6/14/2017
 -----------------------------------------------------------------------------------------------*/

#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <iostream>
#include <vector>

namespace MatLib
{

namespace ArrayStore
{
class Array2d
{
    public:
        Array2d();
        Array2d(unsigned int wid, unsigned int hgt);
        void printMatrix() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;
        unsigned int getNonZeroNum() const;
        Array2d getNegMatrix() const;
        Array2d transpose() const;

        void insertElem(unsigned int row, unsigned int col, int val);

        void operator=(const Array2d &M);
        bool operator==(const Array2d &M) const;
        Array2d operator+(const Array2d &M);
        Array2d operator-(const Array2d &M);
        Array2d operator*(const Array2d &M);


        virtual ~Array2d();
        std::vector<std::vector<int>> data;
    protected:
        unsigned int matrixWidth; unsigned int matrixHeight;
    private:
};


}

}
#endif // ARRAY2D_H
