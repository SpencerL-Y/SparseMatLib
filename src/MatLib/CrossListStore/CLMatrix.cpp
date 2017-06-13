#include "MatLib/CrossListStore/CLMatrix.h"

namespace MatLib
{

namespace CrossListStore
{



CLMatrix::CLMatrix()
{
    std::shared_ptr<CLNode> pushNode;
    pushNode = std::make_shared<CLNode>(0, 0, 0);
    this->rowHead.push_back(pushNode); this->colHead.push_back(pushNode);
    //ctor
}
CLMatrix::CLMatrix(unsigned int wid, unsigned int hgt, unsigned int nonZero)
{
    /* constructor with parameter
     *
     */
    this->width = wid; this->height = hgt; this->nonZeroNum = nonZero;
    std::shared_ptr<CLNode> pushNode; pushNode = std::make_shared<CLNode>(0, 0, 0);
    this->rowHead.push_back(pushNode); this->colHead.push_back(pushNode);
    for(unsigned int i = 1; i <= wid; i++)
    {
        std::shared_ptr<CLNode> push;
        push = std::make_shared<CLNode>(0, i, 0);
        this->rowHead.push_back(push);
    }
    for(unsigned int j = 1; j <= hgt; j++)
    {
        std::shared_ptr<CLNode> push;
        push = std::make_shared<CLNode>(j, 0, 0);
        this->colHead.push_back(push);
    }
}


void CLMatrix::insertNode(CLNode ins)
{
    /* TODO: Insert a CLNode to CLMatrix
     *
     */

    if(ins.getColNum() > this->getHeight() || ins.getRowNum() > this->getWidth())
    {
        std::cout << "insert CLNode Size Error" << '\n';
        return;
    }
    std::shared_ptr<CLNode> temp = this->rowHead[ins.getRowNum()];
    while(temp && temp->right && temp->right->getColNum() < ins.getColNum())
    {
        temp = temp->right;
    }
    if(temp && temp->right->getColNum() == ins.getColNum())
    {
        std::cout << "Element existed, insert failed" << '\n';
        return;
    }
    else
    {
        temp->createRightNode(ins.getRowNum(), ins.getColNum(), ins.getVal());
        std::shared_ptr<CLNode> ptrToNode = temp->right;
        temp = this->colHead[ins.getColNum()];
        while(temp && temp->down && temp->down->getRowNum()<ins.getRowNum())
        {
            temp = temp->down;
        }
        std::shared_ptr<CLNode> exchange = temp->down;
        temp->down = ptrToNode;
        temp->down->down = exchange;
        return ;
    }
}

unsigned int CLMatrix::getWidth() const
{
    return this->width;
}
unsigned int CLMatrix::getHeight() const
{
    return this->height;
}
unsigned int CLMatrix::getNonZero() const
{
    return this->nonZeroNum;
}

CLMatrix::~CLMatrix()
{
    //dtor
}

}
}
