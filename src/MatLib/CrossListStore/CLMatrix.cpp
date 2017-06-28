#include "MatLib/CrossListStore/CLMatrix.h"

namespace MatLib
{
namespace CrossListStore
{
template<typename T>
CLMatrix<T>::CLMatrix()
{
    std::shared_ptr<CLNode<T>> pushNode;
    pushNode = std::make_shared<CLNode<T>>(0, 0, 0);
    this->rowHead.push_back(pushNode);
    this->colHead.push_back(pushNode);
    //ctor
}

template<typename T>
CLMatrix<T>::CLMatrix(unsigned int wid,\
                      unsigned int hgt,\
                      unsigned int nonZero)
{
    /* constructor with parameter
     * Debugged
     */
    this->width = wid;
    this->height = hgt;
    this->nonZeroNum = nonZero;

    std::shared_ptr<CLNode<T>> pushNode; pushNode = std::make_shared<CLNode<T>>(0, 0, 0);
    this->rowHead.push_back(pushNode);
    this->colHead.push_back(pushNode);
    for(unsigned int i = 1; i <= wid; i++)
    {
        std::shared_ptr<CLNode<T>> push;
        push = std::make_shared<CLNode<T>>(i, 0, 0);
        this->rowHead.push_back(push);
    }
    for(unsigned int j = 1; j <= hgt; j++)
    {
        std::shared_ptr<CLNode<T>> push;
        push = std::make_shared<CLNode<T>>(0, j, 0);
        this->colHead.push_back(push);
    }
}

template <typename T>
void CLMatrix<T>::insertNode(CLNode<T> ins)
{
    /* TODO: Insert a CLNode to CLMatrix
     * Debugged
     */
    if(ins.getColNum() > this->getHeight() ||\
       ins.getRowNum() > this->getWidth())//right size
    {
        std::cout << "insert CLNode Size Error" << '\n';
        return;
    }
    std::shared_ptr<CLNode<T>> temp = this->rowHead[ins.getRowNum()];
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
    temp->createRightNode(ins.getRowNum(),\
                          ins.getColNum(),\
                          ins.getVal());
    std::shared_ptr<CLNode<T>> ptrToNode = temp->right;
    temp = this->colHead[ins.getColNum()];
    while(temp->down && temp->down->getRowNum()<ins.getRowNum())
    {
        temp = temp->down;
    }
    std::shared_ptr<CLNode<T>> exchange = temp->down;
    temp->down = ptrToNode;
    temp->down->down = exchange;
    return ;
}

template <typename T>
void CLMatrix<T>::insertNode(unsigned int row,\
                             unsigned int col,\
                             T val)
{
    CLNode<T> ins(row, col, val);
    this->insertNode(ins);
}

template <typename T>
void CLMatrix<T>::printMatrix() const
{
    /* Debugged */
    std::cout << "CLMatrix Print:" << '\n';
    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        this->rowHead[i]->printRightListVal(this->getHeight());
    }
    return ;
}


template <typename T>
bool CLMatrix<T>::operator==(const CLMatrix<T> &M) const
{
    /* Debugged */
    if(this->getHeight()!= M.getHeight() || this->getWidth()!=M.getWidth())
    {
        return false;
    }
    for(unsigned int i = 1; i <= this->getWidth(); i++)//for each row
    {
        std::shared_ptr<CLNode<T>> first = this->rowHead[i]->right;
        std::shared_ptr<CLNode<T>> second = M.rowHead[i]->right;
        while(first && second)// for each col
        {
            if(first->getColNum() != second->getColNum() ||\
               first->getVal() != second->getVal())
            {
                return false;
            }
            first = first->right;
            second = second->right;
        }
        if(first || second){return false;}
    }
    return true;
}

template <typename T>
CLMatrix<T> CLMatrix<T>::getNegMat() const
{
    CLMatrix<T> Temp(this->getWidth(),\
                     this->getHeight(), this->getNonZero());

    for(unsigned i = 1; i <= this->width; i++)
    {
        std::shared_ptr<CLNode<T>> temp = this->rowHead[i]->right;
        while(temp)
        {
            Temp.insertNode(temp->getRowNum(), \
                            temp->getColNum(), -(temp->getVal()));
            temp = temp->right;
        }
    }
    return Temp;
}

template <typename T>
void CLMatrix<T>::operator=(const CLMatrix<T> &M)
{
    /* Debugged */
    //header re-initialization
    this->width = M.getWidth();
    this->height = M.getHeight();
    this->nonZeroNum = M.getNonZero();

    this->rowHead.clear(); this->colHead.clear();
    std::shared_ptr<CLNode<T>> pushNode; pushNode = std::make_shared<CLNode<T>>(0, 0, 0);
    this->rowHead.push_back(pushNode);
    this->colHead.push_back(pushNode);
    for(unsigned int i = 1; i <= this->width; i++)
    {
        std::shared_ptr<CLNode<T>> push;
        push = std::make_shared<CLNode<T>>(i, 0, 0);
        this->rowHead.push_back(push);
    }
    for(unsigned int j = 1; j <= this->height; j++)
    {
        std::shared_ptr<CLNode<T>> push;
        push = std::make_shared<CLNode<T>>(0, j, 0);
        this->colHead.push_back(push);
    }
    //insertNodes

    for(unsigned int i = 1; i <= M.getWidth(); i++)
    {
        std::shared_ptr<CLNode<T>> temp = M.rowHead[i]->right;
        while(temp)
        {
            this->insertNode(temp->getRowNum(),\
                             temp->getColNum(),\
                             temp->getVal());
            temp = temp->right;
        }
    }

    return;
}

template <typename T>
CLMatrix<T> CLMatrix<T>::operator+(const CLMatrix<T> &M)
{
    /* TODO: Add Two CLMatrix<T>
     * Debugged
     */
    if(this->getWidth()!=M.getWidth() ||\
       this->getHeight()!=M.getHeight())//the size of two matrices is different
    {
        std::cout << "ERROR Adding size incompatible." << '\n';
        return *this;
    }
    CLMatrix<T> Temp(this->getWidth(),\
                  this->getHeight(), 0);//new matrix
    //traverse rowHead
    for(unsigned int i = 1; i<=this->getWidth(); i++)
    {
        //pointer to identify position
        std::shared_ptr<CLNode<T>> first = this->rowHead[i]->right;
        std::shared_ptr<CLNode<T>> second = M.rowHead[i]->right;
        while(first && second)
        {
            //same position
            if(first->getColNum() == second->getColNum())
            {
                T sum = first->getVal()+second->getVal();
                if(sum != 0)
                {
                    Temp.insertNode(first->getRowNum(),\
                                    first->getColNum(),\
                                    sum);//Insert method can be improved later.
                }
                first = first->right;
                second = second->right;
            }
            //deferent position
            else if(first->getColNum() < second->getColNum())
            {
                Temp.insertNode(first->getRowNum(),\
                                first->getColNum(),\
                                first->getVal());
                first = first->right;
            }
            else if(first->getColNum() > second->getColNum())
            {
                Temp.insertNode(second->getRowNum(),\
                                second->getColNum(),\
                                second->getVal());
                second = second->right;
            }
            else{std::cout << "ERROR adding" << '\n'; return *this;}
        }
        while(first)
        {
            Temp.insertNode(first->getRowNum(),\
                            first->getColNum(),\
                            first->getVal());
            first = first->right;
        }
        while(second)
        {
            Temp.insertNode(second->getRowNum(),\
                            second->getColNum(),\
                            second->getVal());
            second = second->right;
        }
    }
    return Temp;
}

template <typename T>
CLMatrix<T> CLMatrix<T>::operator*(const CLMatrix<T> &M)
{
    /* TODO: Matrix Multiplication
     * Debugged
     */
    if(this->getHeight() != M.getWidth())
    {
        std::cout << "ERROR multiplication, size incompatible" << '\n';
        return *this;
    }
    CLMatrix<T> Temp(this->getWidth(), M.getHeight(),0);//result matrix

    for(unsigned int i = 1; i <= this->getWidth(); i++)
    {
        std::vector<int> sumArray(M.getHeight()+1, 0);
        std::shared_ptr<CLNode<T>> first = this->rowHead[i]->right;

        while(first)//traverse this matrix  i-th row
        {
            std::shared_ptr<CLNode<T>> second = M.rowHead[first->getColNum()]->right;
            while(second)//traverse corresponding row in M
            {
                sumArray[second->getColNum()] += (first->getVal())*(second->getVal());
                second = second->right;
            }
            first = first->right;
        }
        for(unsigned int j = 1; j < sumArray.size(); j++)
        {
            if(sumArray[j]!=0)
            {
                Temp.insertNode(i, j, sumArray[j]);
            }
        }
    }
    return Temp;
}

template <typename T>
CLMatrix<T> CLMatrix<T>::operator-(const CLMatrix<T> &M)
{
    CLMatrix<T> Temp(this->getWidth(), this->getHeight(), 0);
    Temp = *this + M.getNegMat();
    return Temp;
}

template <typename T>
unsigned int CLMatrix<T>::getWidth() const
{
    return this->width;
}

template <typename T>
unsigned int CLMatrix<T>::getHeight() const
{
    return this->height;
}

template <typename T>
unsigned int CLMatrix<T>::getNonZero() const
{
    return this->nonZeroNum;
}

template <typename T>
T CLMatrix<T>::getDeterminant()
{

    for(unsigned int i = 0; i <= this->getWidth(); i++)
    {
        this->used.push_back(1);
    }
    return deterCal(1);

}

template <typename T>
T CLMatrix<T>::deterCal(unsigned int colNow)
{

    if(colNow == this->getHeight()-1)
    {
        unsigned int detIndex[2] = {0 ,0};
        T subMat[2][2] = {0};
        for(unsigned int i = 1; i < this->used.size(); i++)
        {
            if(this->used[i])
            {
                if(!detIndex[0])
                {
                    detIndex[0] = i;
                }
                else
                {
                    detIndex[1] = i;
                }
            }
        }
        std::shared_ptr<CLNode<T>> temp;
        temp = this->colHead[colNow]->down;
        while(temp)
        {
            if(this->used[temp->getRowNum()] == 1)
            {
                if(detIndex[0] == temp->getRowNum())
                {
                    subMat[0][0] = temp->getVal();
                }
                else
                {
                    subMat[0][1] = temp->getVal();
                }
            }
            temp = temp->down;
        }
        temp = this->colHead[colNow+1]->down;
        while(temp)
        {
            if(this->used[temp->getRowNum()] == 1)
            {
                if(detIndex[0] == temp->getRowNum())
                {
                    subMat[1][0] = temp->getVal();
                }
                else
                {
                    subMat[1][1] = temp->getVal();
                }
            }
            temp = temp->down;
        }
        return (subMat[0][0]*subMat[1][1] -
                subMat[1][0]*subMat[0][1]);
    }
    else
    {
        T det = 0;
        std::shared_ptr<CLNode<T>> temp = this->colHead[colNow]->down;
        while(temp)
        {
            if(this->used[temp->getRowNum()])
            {
                int parity = ((temp->getRowNum() + colNow) & 0x1)? -1: 1;
                this->used[temp->getRowNum()] = 0;
                det += parity * temp->getVal() * deterCal(colNow+1);
                this->used[temp->getRowNum()] = 1;
            }
            temp = temp->down;
        }
        return det;
    }

}

template <typename T>
T CLMatrix<T>::naive_getCofactor(unsigned int row, unsigned int col)
{
    CLMatrix<T> Temp(this->getWidth()-1, this->getHeight()-1, 0);
    for(unsigned int i = 1; i < row; i++)
    {
        std::shared_ptr<CLNode<T>> temp = rowHead[i]->right;
        while(temp)
        {
            if(temp->getColNum() < col)
            {
                Temp.insertNode(temp->getRowNum(),
                                temp->getColNum(),
                                temp->getVal());
            }
            else
            {
                if(temp->getColNum() == col){;}
                else{Temp.insertNode(temp->getRowNum(),
                                     temp->getColNum()-1,
                                     temp->getVal());}
            }
            temp = temp->right;
        }
    }
    for(unsigned int i = row+1; i <= this->getWidth(); i++)
    {
        std::shared_ptr<CLNode<T>> temp = rowHead[i]->right;
        while(temp)
        {
            if(temp->getColNum() < col)
            {
                Temp.insertNode(temp->getRowNum()-1,
                                temp->getColNum(),
                                temp->getVal());
            }
            else
            {
                if(temp->getColNum() == col){;}
                else{Temp.insertNode(temp->getRowNum()-1,
                                     temp->getColNum()-1,
                                     temp->getVal());}
            }
            temp = temp->right;

        }
    }
    int parity = ((row + col) & 0x1)? -1: 1;
    return parity*Temp.getDeterminant();
}

template <class T>
CLMatrix<T> CLMatrix<T>::getInverseMatrix()
{
    CLMatrix<T> Temp(this->getHeight(),
                     this->getWidth(), 0);
    T det = this->getDeterminant();
    if(!det)
    {
        std::cout << "CLMatrix not invertible." << '\n';
    }
    for(unsigned int i = 1; i < this->rowHead.size(); i++)
    {
        std::shared_ptr<CLNode<T>> temp = this->rowHead[i]->right;
        while(temp)
        {
            double coef = (naive_getCofactor(i, temp->getColNum())/det);
            /*std::cout << "row: " << i << "col: "
                      << temp->getColNum() << "coef: "
                      << coef << '\n';*/
            Temp.insertNode(temp->getColNum(), i, coef);
            temp = temp->right;
        }
    }
    return Temp;
}

template <typename T>
CLMatrix<T>::~CLMatrix()
{
    //dtor
}


template class CLMatrix<double>;
template class CLMatrix<int>;
}//CrossListStore
}//MatLib
