
#include "MatLib/CrossListStore/CLNode.h"

namespace MatLib
{


namespace CrossListStore
{



CLNode::CLNode()
{
    //ctor
}
CLNode::CLNode(unsigned int row, unsigned int col, int val)
{
    this->rowNum = row; this->colNum = col;
    this->value = val;
}




void CLNode::modifyNode(unsigned int row, unsigned int col, int val)
{
    /* Debugged */
    this->rowNum = row; this->colNum = col;
    this->value = val;
}

void CLNode::createDownNode(unsigned int row, unsigned int col, int val)
{
    /* Debugged */
    this->down = std::make_shared<CLNode>(row, col, val);
}

void CLNode::createRightNode(unsigned int row, unsigned int col, int val)
{
    /* Debugged */
    this->right = std::make_shared<CLNode>(row, col, val);
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
    std::cout << this->rowNum << '\t' << this->colNum << '\t' << this->value << '\n';
}
void CLNode::printRightList() const
{
    std::cout << this->rowNum << '\t' << this->colNum << '\t' << this->value << '\n';
    std::shared_ptr<CLNode> prtptr = this->right;
    while(prtptr)
    {
        prtptr->printNode();
        prtptr = prtptr->right;

    }
}
void CLNode::printDownList() const
{
    std::cout << this->rowNum << '\t' << this->colNum << '\t' << this->value << '\n';
    std::shared_ptr<CLNode> prtptr = this->down;
    while(prtptr)
    {
        prtptr->printNode();
        prtptr = prtptr->down;

    }
}






CLNode::~CLNode()
{
    std::cout << "CLNode destructed" << '\n';
    //dtor
}


}

}
