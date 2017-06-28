/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: CLMatrix
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 6/7/2017
 * Last Modified: 6/14/2017
 -----------------------------------------------------------------------------------------------*/

#ifndef CLMATRIX_H
#define CLMATRIX_H
#include <MatLib/CrossListStore/CLNode.h>

namespace MatLib
{

namespace CrossListStore
{


template <typename T>
class CLMatrix
{
    public:
        CLMatrix();
        CLMatrix(unsigned int wid, unsigned int hgt, unsigned int nonZero);
        virtual ~CLMatrix();

        void insertNode(CLNode<T> ins);
        void insertNode(unsigned int row, unsigned int col, T val);
        void printMatrix() const;
        void operator=(const CLMatrix &M);
        bool operator==(const CLMatrix &M) const;
        CLMatrix getNegMat() const;
        CLMatrix operator+(const CLMatrix &M);
        CLMatrix operator*(const CLMatrix &M);
        CLMatrix operator-(const CLMatrix &M);

        unsigned int getWidth() const;
        unsigned int getHeight() const;
        unsigned int getNonZero() const;
        T getDeterminant();
        T naive_getCofactor(unsigned int row, unsigned int col);
        CLMatrix getInverseMatrix();

        std::vector<std::shared_ptr<CLNode<T>>> rowHead;
        std::vector<std::shared_ptr<CLNode<T>>> colHead;
        std::vector<int> used;


    protected:
        unsigned int width; unsigned int height;
        unsigned int nonZeroNum;
    private:
        T deterCal(unsigned int colNow);



};


}

}
#endif // CLMATRIX_H
