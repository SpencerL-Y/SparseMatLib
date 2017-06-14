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
     * Debugged
     */
    this->width = wid; this->height = hgt; this->nonZeroNum = nonZero;
    std::shared_ptr<CLNode> pushNode; pushNode = std::make_shared<CLNode>(0, 0, 0);
    this->rowHead.push_back(pushNode); this->colHead.push_back(pushNode);
    for(unsigned int i = 1; i <= wid; i++)
    {
        std::shared_ptr<CLNode> push;
        push = std::make_shared<CLNode>(i, 0, 0);
        this->rowHead.push_back(push);
    }
    for(unsigned int j = 1; j <= hgt; j++)
    {
        std::shared_ptr<CLNode> push;
        push = std::make_shared<CLNode>(0, j, 0);
        this->colHead.push_back(push);
    }
}


void CLMatrix::insertNode(CLNode ins)
{
    /* TODO: Insert a CLNode to CLMatrix
     * Debugged
     */

    if(ins.getColNum() > this->getHeight() || ins.getRowNum() > this->getWidth())//right size
    {
        std::cout << "insert CLNode Size Error" << '\n';
        return;
    }
    std::shared_ptr<CLNode> temp = this->rowHead[ins.getRowNum()];
    while(temp->right && temp->right->getColNum() < ins.getColNum())//find position in row
    {
        temp = temp->right;
    }
    if(temp->right)
    {
        if(temp->right->getColNum() == ins.getColNum())//whether element existed
        {
            std::cout << "Element existed, insert failed" << '\n';
            return;
        }
    }
    //insert the node in row and col
    temp->createRightNode(ins.getRowNum(), ins.getColNum(), ins.getVal());
    std::shared_ptr<CLNode> ptrToNode = temp->right;
    temp = this->colHead[ins.getColNum()];
    while(temp->down && temp->down->getRowNum()<ins.getRowNum())
    {
        temp = temp->down;
    }
    std::shared_ptr<CLNode> exchange = temp->down;
    temp->down = ptrToNode;
    temp->down->down = exchange;
    return ;
}


void CLMatrix::insertNode(unsigned int row, unsigned int col, int val)
{
    CLNode ins(row, col, val);
    this->insertNode(ins);
}


void CLMatrix::printMatrix() const
{
    /* Debugged */
    std::cout << "CLMatrix Print:" << '\n';
    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        this->rowHead[i]->printRightListVal(this->getHeight());
    }
    return ;
}



bool CLMatrix::operator==(const CLMatrix &M) const
{
    /* Debugged */
    if(this->getHeight()!= M.getHeight() || this->getWidth()!=M.getWidth())
    {
        return false;
    }
    for(unsigned int i = 1; i <= this->getWidth(); i++)//for each row
    {
        std::shared_ptr<CLNode> first = this->rowHead[i]->right;
        std::shared_ptr<CLNode> second = M.rowHead[i]->right;
        while(first && second)// for each col
        {
            if(first->getColNum() != second->getColNum() || first->getVal() != second->getVal())
            {
                return false;
            }
            first = first->right; second = second->right;
        }
        if(first || second){return false;}
    }
    return true;
}
void CLMatrix::operator=(const CLMatrix &M)
{
    /* Debugged */
    this->width = M.getWidth(); this->height = M.getHeight();
    this->nonZeroNum = M.getNonZero();
    //header re-initialization
    for(unsigned int i = 1; i <= this->width; i++)
    {
        std::shared_ptr<CLNode> push;
        push = std::make_shared<CLNode>(i, 0, 0);
        this->rowHead.push_back(push);
    }
    for(unsigned int j = 1; j <= this->height; j++)
    {
        std::shared_ptr<CLNode> push;
        push = std::make_shared<CLNode>(0, j, 0);
        this->colHead.push_back(push);
    }


    //insertNodes
    for(unsigned int i = 1; i <= M.getWidth(); i++)
    {
        std::shared_ptr<CLNode> temp = M.rowHead[i]->right;
        while(temp)
        {
            this->insertNode(temp->getRowNum(), temp->getColNum(), temp->getVal());
            temp = temp->right;
        }
    }

    return;
}


CLMatrix CLMatrix::operator+(const CLMatrix &M)
{
    /* TODO: Add66
     *
     */
    if(this->getWidth()!=M.getWidth() || this->getHeight()!=M.getHeight())//the size of two matrices is different
    {
        std::cout << "ERROR Adding size incompatible." << '\n';
        return *this;
    }
    CLMatrix Temp(this->getWidth(), this->getHeight(), 0);//new matrix
    for(unsigned int i = 1; i<=this->getWidth(); i++)//traverse rowHead
    {
        std::shared_ptr<CLNode> first = this->rowHead[i]->right;//pointer to identify position
        std::shared_ptr<CLNode> second = M.rowHead[i]->right;
        while(first && second)
        {
            //same position
            if(first->getColNum() == second->getColNum())
            {
                int sum = first->getVal()+second->getVal();
                if(sum != 0)
                {
                    Temp.insertNode(first->getRowNum(), first->getColNum(), sum);//Insert method can be improved later.
                }
                first = first->right; second = second->right;
            }
            //deferent position
            else if(first->getColNum() < second->getColNum())
            {
                Temp.insertNode(first->getRowNum(), first->getColNum(), first->getVal());
                first = first->right;
            }
            else if(first->getColNum() > second->getColNum())
            {
                Temp.insertNode(second->getRowNum(), second->getColNum(), second->getVal());
                second = second->right;
            }
            else{std::cout << "ERROR adding" << '\n'; return *this;}
        }
        while(first)
        {
            Temp.insertNode(first->getRowNum(), first->getColNum(), first->getVal());
            first = first->right;
        }
        while(second)
        {
            Temp.insertNode(second->getRowNum(), second->getColNum(), second->getVal());
            second = second->right;
        }
    }
    return Temp;
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
