#ifndef CLMATRIX_H
#define CLMATRIX_H
#include <MatLib/CrossListStore/CLNode.h>
namespace MatLib
{

namespace CrossListStore
{



class CLMatrix
{
    public:
        CLMatrix();
        CLMatrix(unsigned int wid, unsigned int hgt, unsigned int nonZero);
        virtual ~CLMatrix();

        void resizeMatrix(unsigned int wid, unsigned int hgt, unsigned int nonZero);
        void insertNode(CLNode ins);

        CLMatrix operator=(const CLMatrix &M);
        bool operator==(const CLMatrix &M) const;
        CLMatrix operator+(const CLMatrix &M);
        CLMatrix operator*(const CLMatrix &M);

        unsigned int getWidth() const;
        unsigned int getHeight() const;
        unsigned int getNonZero() const;
        std::vector<std::shared_ptr<CLNode>> rowHead;
        std::vector<std::shared_ptr<CLNode>> colHead;
    protected:
        unsigned int width; unsigned int height;
        unsigned int nonZeroNum;
    private:
};


}

}
#endif // CLMATRIX_H
