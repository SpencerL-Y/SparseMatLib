#include "CLMatrix.h"

CLMatrix::CLMatrix()
{
    this->rowHead.push_back(pushNode); this->colHead.push_back(pushNode);
    //ctor
}
CLMatrix::CLMatrix(unsigned int wid, unsigned int hgt, unsigned int nonZero)
{
    /* constructor with parameter
     *
     */
    this->width = wid; this->height = hgt; this->nonZeroNum = nonZero;
    CLNode pushNode(0, 0, 0);
    this->rowHead.push_back(pushNode); this->colHead.push_back(pushNode);
    for(unsigned int i = 1; i <= wid; i++)
    {
        CLNode push(0, i, 0); this->rowHead.push_back(push);
    }
    for(unsigned int j = 1; j <= hgt; j++)
    {
        CLNode push(i, 0, 0); this->colHead.push_back(push)
    }
}




CLMatrix::~CLMatrix()
{
    //dtor
}
