#include <iostream>

#include "MatLib/CSRStore/CSRMatrix.h"

namespace MatLib
{

namespace CSRStore
{


CSRMatrix::CSRMatrix()
{
    //ctor
}

void CSRMatrix::displayTable() const
{
    std::cout << '\n'<< "CSRTuple Array:" << '\n';
    for(int i = 1; i < MAXSIZE && data[i].getColNum()!=0 ; i++)
    {
        std::cout << data[i].getColNum() << '\t';
    }
    std::cout << '\n';
    for(int i = 1; i < MAXSIZE && data[i].getVal()!=0; i++)
    {
        std::cout << data[i].getVal() << '\t';
    }
    std::cout << '\n' << "CSR Row Pointer Array:" << '\n';
    for(unsigned int i = 1; i <= matrixWidth; i++)
    {
        std::cout << rowPtr[i] << '\t';
    }
    std::cout << '\n';
}


//instance modifying
void CSRMatrix::createCSRMatrix(unsigned int matWid, unsigned int matHgt)
{
    matrixWidth = matWid; matrixHeight = matHgt;
    CSRTuple deft; deft.modifyTuple(0,0);
    for(int i = 0; i < MAXSIZE; i++)
    {
        rowPtr[i] = 0;
        data[i] = deft;
    }


}

unsigned int CSRMatrix::getMatrixWidth() const
{
    return matrixWidth;
}

unsigned int CSRMatrix::getMatrixHeight() const
{
    return matrixHeight;
}

unsigned int CSRMatrix::getMatrixNonZeroNum() const
{
    unsigned int i;
    for(i = 0; i< MAXSIZE && data[i].getColNum()!=0; i++)
    {
        ;
    }
    return i+1;
}

void CSRMatrix::insertTupleToMatrix(unsigned int rowNum, CSRTuple ins)
{
    unsigned insPos;
    if(rowPtr[rowNum] == 0)
    {
        unsigned int k = rowNum+1;
        while(k <= matrixWidth && rowPtr[k] == 0)
        {
            k++;
        }
        unsigned int insNow = (k > matrixWidth)? 0:  rowPtr[k];
        if(insNow == 0){for(insPos = 1; data[insPos].getColNum()!=0; insPos++);}
        else {for(insPos = 1; insPos < insNow; insPos++);}
        rowPtr[rowNum] = insPos;
    }
    else
    {
        insPos = rowPtr[rowNum];
        if(rowPtr[rowNum+1] == 0)
        {
            while(ins.getColNum() > data[insPos].getColNum()){insPos++;}
        }
        else
        {
            while(ins.getColNum() > data[insPos].getColNum() && insPos < rowPtr[rowNum+1]){insPos++;}
        }
    }
    unsigned int k = 1;
    for(k = 1; data[k].getColNum()!=0; k++);
    unsigned int j;
    for(j = k; j > insPos; j--)
    {
        data[j] = data[j-1];
    }
    data[j] = ins;
    for(unsigned int i = rowNum+1; i <= matrixWidth; i++)
    {
        if(rowPtr[i]!=0)
        {
            rowPtr[i]++;
        }
    }
}


void CSRMatrix::printMatrix() const
{
    unsigned int i = 1;
    std::cout << "CSRMatrix Print:" << '\n';
    while(rowPtr[i]!=0)
    {
        unsigned int colNow = 1;
        for(unsigned int j = rowPtr[i];colNow <= matrixWidth; colNow++)
        {
            if(colNow == data[j].getColNum())
            {
                std::cout << data[j].getVal() << '\t';
                j++;
            }
            else
            {
                std::cout << 0 << '\t';
            }

        }
        std::cout << '\n';
        i++;
    }
}


void CSRMatrix::destroyMatrix()
{
    matrixWidth = 0; matrixHeight = 0;
    for(unsigned int i = 0; i < MAXSIZE; i++)
    {
        data[i].modifyTuple(0, 0);
        rowPtr[i] = 0;
    }
}

void CSRMatrix::operator=(const CSRMatrix &M)
{
    this->matrixWidth = M.matrixWidth;
    this->matrixHeight = M.matrixHeight;
    for(unsigned int i = 1; i < MAXSIZE; i++)
    {
        this->rowPtr[i] = M.rowPtr[i];
        this->data[i] = M.data[i];
    }
}


bool CSRMatrix::operator==(const CSRMatrix &M) const
{
    if(matrixHeight != M.getMatrixHeight() || matrixWidth != M.getMatrixWidth())
    {
        std::cout << "Compare Size Error." << '\n';
        return 0;
    }
    else
    {
        for(unsigned int i = 0; i < MAXSIZE; i++)
        {
            if(!(data[i] == M.data[i]) || rowPtr[i] != M.rowPtr[i])
            {
                return 0;
            }
        }
        return 1;
    }
}
//Not Debugged
CSRMatrix CSRMatrix::operator+(const CSRMatrix &M)
{
    if(this->getMatrixWidth() != M.getMatrixWidth() || this->getMatrixHeight()!=M.getMatrixHeight())
    {
        std::cout << "Unable to Add." << '\n';
        return *this;
    }
    CSRMatrix temp; unsigned int now = 1; unsigned int i = 0;
    unsigned int first = 0; unsigned int second = 0;
    for(i = 1; i < this->getMatrixWidth(); i++)
    {
        first = this->rowPtr[i]; second = M.rowPtr[i];
        if(first == 0 && second == 0) {continue;}
        if(first != 0 && second == 0)
        {
            while(first < this->rowPtr[i+1])
            {
                temp.data[now] = this->data[first];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                now++; first ++;
            }
            continue;
        }
        if(first == 0 && second != 0)
        {
            while(second < M.rowPtr[i+1])
            {
                temp.data[now] = M.data[second];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                now++; second++;
            }
            continue;
        }
        while(first < this->rowPtr[i+1] && second < M.rowPtr[i+1] && first && second)
        {
            if(this->data[first].getColNum() < M.data[second].getColNum())
            {
                temp.data[now] = this->data[first];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                first++; now++;
            }
            else if(this->data[first].getColNum() == M.data[second].getColNum())
            {
                temp.data[now] = this->data[first] + M.data[second];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                first++; second++; now++;
            }
            else if(this->data[first].getColNum() > M.data[second].getColNum())
            {
                temp.data[now] = M.data[second];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                second++; now++;
            }
            else
            {
                ;
            }

        }
        while(first < this->rowPtr[i+1])
        {
            temp.data[now] = this->data[first];
            now++; first++;
        }
        while(second < M.rowPtr[i+1])
        {
            temp.data[now] = M.data[second];
            now++; first++;
        }

    }
    if(i == this->getMatrixWidth())
    {
        first = this->rowPtr[i]; second = M.rowPtr[i];
        if(first == 0 && second == 0) {return temp;}
        if(first != 0 && second == 0)
        {
            while(this->data[first].getColNum())
            {
                temp.data[now] = this->data[first];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                now++; first ++;
            }
            return temp;
        }
        if(first == 0 && second != 0)
        {
            while(M.data[second].getColNum())
            {
                temp.data[now] = M.data[second];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                now++; second++;
            }
            return temp;
        }

        while(this->data[first].getColNum() && M.data[second].getColNum() && first && second)
        {
            if(this->data[first].getColNum() < M.data[second].getColNum())
            {
                temp.data[now] = this->data[first];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                first++; now++;
            }
            else if(this->data[first].getColNum() == M.data[second].getColNum())
            {
                temp.data[now] = this->data[first] + M.data[second];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                first++; second++; now++;
            }
            else if(this->data[first].getColNum() > M.data[second].getColNum())
            {
                temp.data[now] = M.data[second];
                if(first == this->rowPtr[i] && second == M.rowPtr[i])
                {
                    temp.rowPtr[i] = now;
                }
                second++; now++;
            }
            else
            {
                ;
            }

        }
        while(this->data[first].getColNum())
        {
            temp.data[now] = this->data[first];
            now++; first++;
        }
        while(M.data[second].getColNum())
        {
            temp.data[now] = M.data[second];
            now++; first++;
        }

    }
    return temp;
}

CSRMatrix CSRMatrix::getNegMat() const
{
    CSRMatrix temp;
    temp.matrixWidth = this->matrixWidth;
    temp.matrixHeight = this->matrixHeight;
    for(unsigned int i = 1; i < MAXSIZE; i++)
    {
        temp.data[i].modifyTuple(this->data[i].getColNum(), -(this->data[i].getVal()));
    }
    return temp;
}

CSRMatrix::~CSRMatrix()
{
    //dtor
}

}

}
