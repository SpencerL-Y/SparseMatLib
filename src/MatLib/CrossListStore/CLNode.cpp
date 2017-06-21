
#include "MatLib/CrossListStore/CLNode.h"

namespace MatLib
{
namespace CrossListStore
{

CLNode::CLNode()
{
    //ctor
}

CLNode::CLNode(unsigned int row,\
               unsigned int col, int val)
{
    this->rowNum = row;
    this->colNum = col; this->value = val;
}

void CLNode::modifyNode(unsigned int row,\
                        unsigned int col, int val)
{
    /* Debugged */
    this->rowNum = row;
    this->colNum = col; this->value = val;
}

void CLNode::createDownNode(unsigned int row,\
                            unsigned int col, int val)
{
    /* Debugged */
    std::shared_ptr<CLNode> temp = this->down;
    this->down = std::make_shared<CLNode>(row, col, val);
    this->down->down = temp;
}

void CLNode::createRightNode(unsigned int row,\
                             unsigned int col, int val)
{
    /* Debugged */
    std::shared_ptr<CLNode> temp = this->right;
    this->right = std::make_shared<CLNode>(row, col, val);
    this->right->right = temp;
}

void CLNode::deleteDownNode()
{
    /* TODO: delete the down node of this node
     * Debugged
     */
    std::shared_ptr<CLNode> temp;
    temp = this->down;
    this->down = temp->down;
}

void CLNode::deleteRightNode()
{
    /* TODO: delete the right node of this node
     * Debugged
     */
    std::shared_ptr<CLNode> temp;
    temp = this->right;
    this->right = temp->right;
}

void CLNode::printNode() const
{
    std::cout << this->rowNum << '\t'\
              << this->colNum << '\t' << this->value << '\n';
}

void CLNode::printRightList() const
{
    std::cout << this->rowNum << '\t'\
              << this->colNum << '\t' << this->value << '\n';
    std::shared_ptr<CLNode> prtptr = this->right;
    while(prtptr)
    {
        prtptr->printNode();
        prtptr = prtptr->right;

    }
}

void CLNode::printDownList() const
{
    std::cout << this->rowNum << '\t' \
              << this->colNum << '\t' << this->value << '\n';
    std::shared_ptr<CLNode> prtptr = this->down;
    while(prtptr)
    {
        prtptr->printNode();
        prtptr = prtptr->down;
    }
}

void CLNode::printRightListVal(unsigned int hgt) const
{
    /* Debugged */
    std::shared_ptr<CLNode> temp = this->right;
    for(unsigned int i = 1; i <= hgt; i++)
    {
        if(temp && temp->getColNum() == i)
        {
            std::cout << temp->getVal() << '\t';
            temp = temp->right;
        }
        else
        {
            std::cout << 0 << '\t';
        }
    }
    std::cout << '\n';
    return;
}

unsigned int CLNode::getRowNum() const
{
    return this->rowNum;
}

unsigned int CLNode::getColNum() const
{
    return this->colNum;
}

int CLNode::getVal() const
{
    return this->value;
}

CLNode::~CLNode()
{
    //std::cout << "CLNode destructed" << '\n';
    //dtor
}

}//CrossListStore
}//MatLib
