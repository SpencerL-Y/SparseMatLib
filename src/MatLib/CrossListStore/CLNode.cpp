#include "MatLib/CrossListStore/CLNode.h"

namespace MatLib
{
namespace CrossListStore
{

template <typename T>
CLNode<T>::CLNode()
{
    //ctor
}

template <typename T>
CLNode<T>::CLNode(unsigned int row,\
               unsigned int col, T val)
{
    this->rowNum = row;
    this->colNum = col; this->value = val;
}

template <typename T>
void CLNode<T>::modifyNode(unsigned int row,\
                           unsigned int col, T val)
{
    /* Debugged */
    this->rowNum = row;
    this->colNum = col; this->value = val;
}

template <typename T>
void CLNode<T>::createDownNode(unsigned int row,\
                               unsigned int col, T val)
{
    /* Debugged */
    std::shared_ptr<CLNode<T>> temp = this->down;
    this->down = std::make_shared<CLNode<T>>(row, col, val);
    this->down->down = temp;
}

template <typename T>
void CLNode<T>::createRightNode(unsigned int row,\
                                unsigned int col, T val)
{
    /* Debugged */
    std::shared_ptr<CLNode<T>> temp = this->right;
    this->right = std::make_shared<CLNode<T>>(row, col, val);
    this->right->right = temp;
}

template <typename T>
void CLNode<T>::deleteDownNode()
{
    /* TODO: delete the down node of this node
     * Debugged
     */
    std::shared_ptr<CLNode<T>> temp;
    temp = this->down;
    this->down = temp->down;
}

template <typename T>
void CLNode<T>::deleteRightNode()
{
    /* TODO: delete the right node of this node
     * Debugged
     */
    std::shared_ptr<CLNode<T>> temp;
    temp = this->right;
    this->right = temp->right;
}

template <typename T>
void CLNode<T>::printNode() const
{
    std::cout << this->rowNum << '\t'\
              << this->colNum << '\t' << this->value << '\n';
}

template <typename T>
void CLNode<T>::printRightList() const
{
    std::cout << this->rowNum << '\t'\
              << this->colNum << '\t' << this->value << '\n';
    std::shared_ptr<CLNode<T>> prtptr = this->right;
    while(prtptr)
    {
        prtptr->printNode();
        prtptr = prtptr->right;

    }
}

template <typename T>
void CLNode<T>::printDownList() const
{
    std::cout << this->rowNum << '\t' \
              << this->colNum << '\t' << this->value << '\n';
    std::shared_ptr<CLNode<T>> prtptr = this->down;
    while(prtptr)
    {
        prtptr->printNode();
        prtptr = prtptr->down;
    }
}

template <typename T>
void CLNode<T>::printRightListVal(unsigned int hgt) const
{
    /* Debugged */
    std::shared_ptr<CLNode<T>> temp = this->right;
    for(unsigned int i = 1; i <= hgt; i++)
    {
        if(temp && temp->getColNum() == i)
        {
            std::cout << temp->getVal() << '\t' << '\t';
            temp = temp->right;
        }
        else
        {
            std::cout << 0 << '\t'<< '\t';
        }
    }
    std::cout << '\n';
    return;
}

template <typename T>
unsigned int CLNode<T>::getRowNum() const
{
    return this->rowNum;
}

template <typename T>
unsigned int CLNode<T>::getColNum() const
{
    return this->colNum;
}

template <typename T>
T CLNode<T>::getVal() const
{
    return this->value;
}

template <typename T>
CLNode<T>::~CLNode()
{
    //std::cout << "CLNode<T> destructed" << '\n';
    //dtor
}

template class CLNode<double>;
template class CLNode<int>;
}//CrossListStore
}//MatLib
