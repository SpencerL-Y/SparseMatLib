#ifndef CLMATRIX_H
#define CLMATRIX_H
#include <MatLib/CrossListStore/CLNode.h>
class CLMatrix
{
    public:
        CLMatrix();
        CLMatrix(unsigned int wid, unsigned int hgt, unsigned int nonZero);
        virtual ~CLMatrix();
        std::vector<CLNode> rowHead;
        std::vector<CLNode> colHead;
    protected:
        unsigned int width; unsigned int height;
        unsigned int nonZeroNum;
    private:
};

#endif // CLMATRIX_H
