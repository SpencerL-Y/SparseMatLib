

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "MatLib/TripletStore/TripletMatrix.h"
#include "MatLib/TripletStore/Triplet.h"


namespace MatLib
{

namespace TripletStore
{

//constructor

TripletMatrix::TripletMatrix()
{
    /* TODO: Constructor
     * initialize the matrix width 0s and take the position of data[0].
     * Debugged
     */
    matrixWidth = 0; matrixHeight = 0;
    nonZeroNum = 0;
    Triplet a;
    a.modifyTriplet(0,0,0);
    data.push_back(a);

}


inline void TripletMatrix::resizeMatrix(unsigned int width, unsigned int height, unsigned int nonZero)
{
    /* TODO: resize Matrix */
    matrixWidth = width; matrixHeight = height;
    nonZeroNum = nonZero;
}



void TripletMatrix::insertTripletToMatrix(Triplet insertTriplet)
{
   /* TODO: Insert a Triple into the right place of matrix table
    * Debugged
    */
    unsigned int row = insertTriplet.getRowNum();
    unsigned int col = insertTriplet.getColNum();
    unsigned int i;
    for(i = 1; i < data.size() &&  data[i].getColNum() && row > data[i].getRowNum() ; i++) ;
    for(; row == data[i].getRowNum() && col > data[i].getColNum() && i < data.size(); i++);
    if(row == data[i].getRowNum() && col == data[i].getColNum() && i < data.size())
    {
        std::cout << i << ": "<<"getRowNum: " << data[i].getRowNum() << " getColNum: " << data[i].getColNum() << " getVal: " << data[i].getValue()<< '\n';
        std::cout << "row: " << row << "col: " << col<< "ERROR inserting" << '\n';
        return;
    }
    else
    {
        data.insert(data.begin()+i, insertTriplet);
    }
    return ;
}

void TripletMatrix::nonZeroUpdate()
{
    /* TODO: get Non-zero number
     * Debugged
     */
    this->nonZeroNum = this->data.size() - 1;
    //std::cout << this->nonZeroNum;
    return;
}

void TripletMatrix::displayTable() const
{
    /* TODO: Display triple table of a matrix
     * Debugged
     */
    std::cout << "Matrix Table Print:" << '\n';
    for(unsigned int i = 0; i<data.size(); i++)
    {
        std::cout << data[i].getRowNum() << '\t';
    }
    std::cout << '\n';
    for(unsigned int i = 0; i<data.size(); i++)
    {
        std::cout << data[i].getColNum() << '\t';
    }
    std::cout << '\n';
    for(unsigned int i = 0; i<data.size(); i++)
    {
        std::cout << data[i].getValue() << '\t';
    }
    std::cout << '\n';


}

void TripletMatrix::printMatrix() const
{
    /* TODO: Print matrix.
     * Debugged
     */
    std::cout << "TripleMatrix Print:" << '\n';
    unsigned int pos = 1;
    for(unsigned int i = 1; i <= getMatrixWidth(); i++)
    {
        for(unsigned int j = 1; j <= getMatrixHeight();j++)
        {
            if(data[pos].getRowNum() == i && data[pos].getColNum() == j)
            {
                std::cout << data[pos].getValue() << '\t';
                pos++;
            }
            else
            {
                std::cout << 0 << '\t';
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    return;
}

unsigned int TripletMatrix::getMatrixWidth() const
{
    return matrixWidth;
}
unsigned int TripletMatrix::getMatrixHeight() const
{
    return matrixHeight;
}
unsigned int TripletMatrix::getMatrixNonZeroNum() const
{
    return nonZeroNum;
}


// Operators Overload

void TripletMatrix::operator=(const TripletMatrix &M)
{
    /*Debugged*/
    matrixWidth = M.getMatrixWidth(); matrixHeight = M.getMatrixHeight();
    nonZeroNum = M.getMatrixNonZeroNum();
    this->data.assign(M.data.begin(), M.data.end());
    return;

}

bool TripletMatrix::operator==(const TripletMatrix &M) const
{
   /* TODO: Equality Judge
    * Debugged
    */
    if((matrixHeight == M.getMatrixHeight()) && (matrixWidth == M.getMatrixWidth())){;}
    else return false;
    unsigned int i;
    for(i = 1; this->data[i].getRowNum() && M.data[i].getRowNum(); i++)
    {
        if(data[i].getRowNum()!=M.data[i].getRowNum() ||\
           data[i].getColNum()!=M.data[i].getColNum() ||\
           data[i].getValue() !=M.data[i].getValue())
        {
            return false;
        }
    }
    if(i < this->data.size() ||  i < M.data.size())
    {
        return false;
    }
    return true;
    //lixie
}

TripletMatrix TripletMatrix::operator+(const TripletMatrix &M)
{
   /* TODO: ADD
    * Debugged
    */
    if(this->matrixWidth != M.matrixWidth || this->matrixHeight != M.matrixHeight)
    {
        std::cout << "Unable To Add" << '\n';
        return *this;
    }
    TripletMatrix Temp; Temp.resizeMatrix(this->matrixWidth, this->matrixHeight, 0);
    unsigned int i = 1;  unsigned int j = 1;
    while(i < data.size() && j < M.data.size())
    {

        if(data[i].getRowNum() == M.data[j].getRowNum())
        {
            if(data[i].getColNum() < M.data[j].getColNum())
            {
                Temp.data.push_back(data[i]) ; i++;
            }
            else if(data[i].getColNum() == M.data[j].getColNum())
            {
                Triplet sum = data[i] + M.data[j];
                if(sum.getValue())
                {
                    Temp.data.push_back(sum);
                }
                i++; j++;
            }
            else if(data[i].getColNum() > M.data[j].getColNum())
            {
                Temp.data.push_back(M.data[j]); j++;
            }
            else {;}
        }
        else if(data[i].getRowNum() < M.data[j].getRowNum())
        {
            Temp.data.push_back(data[i]); i++;
        }
        else if(data[i].getRowNum() > M.data[j].getRowNum())
        {
            Temp.data.push_back(M.data[j]); j++;
        }
        else {;}
    }
    while(i < data.size())
    {
        Temp.data.push_back(data[i]);
        i++;
    }
    while(j < M.data.size())
    {
        Temp.data.push_back(M.data[j]);
        j++;
    }
    Temp.nonZeroUpdate();
    return Temp;

}

TripletMatrix TripletMatrix::getNegMatrix() const
{
    /* TODO: reverse the value
     * Debugged
     */
    TripletMatrix NegMat; Triplet now;
    NegMat.resizeMatrix(this->getMatrixWidth(), this->getMatrixHeight(), this->getMatrixNonZeroNum());
    for(unsigned int i = 1; i < data.size(); i++)
    {
        cout<<i;
        now.modifyTriplet(data[i].getRowNum(),data[i].getColNum(), -(data[i].getValue()));
        NegMat.data.push_back(now);
    }
    return NegMat;
}

TripletMatrix TripletMatrix::operator*(const TripletMatrix &M)
{
    /* TODO: Multiply
     * Debugged
     */
    TripletMatrix Temp;
    if(this->getMatrixHeight() != M.getMatrixWidth() || this->getMatrixWidth() == 0 || M.getMatrixHeight() == 0)
    {
        std::cout<< "ERROR in Multiplication." << '\n';
        return *this;
    }
    Temp.resizeMatrix(this->getMatrixWidth(), M.getMatrixHeight(), 0);
    //array used to store intermediate result
    vector<int> heightArray(M.getMatrixHeight()+1, 0);


    for(unsigned int tableRow = 1; tableRow <= this->getMatrixWidth(); tableRow++)// Each row
    {
        for(unsigned colNum = 0; colNum <= M.getMatrixHeight(); colNum++)
        {
            heightArray[colNum] = 0;
        }
        for(unsigned int j = 1; j < this->data.size(); j++)//Traverse this Matrix data vector
        {
            if(this->data[j].getRowNum() == tableRow)
            {
                for(unsigned int k = 1; k < M.data.size(); k++)//Traverse M data vector
                {
                    if(this->data[j].getColNum() == M.data[k].getRowNum())
                    {
                        heightArray[M.data[k].getColNum()] += (this->data[j].getValue())*M.data[k].getValue();
                    }
                }
            }
        }
        for(unsigned int colNum = 1; colNum <= M.getMatrixHeight(); colNum++)
        {
            if(heightArray[colNum])
            {
                Triplet add;
                add.modifyTriplet(tableRow, colNum, heightArray[colNum]);
                Temp.insertTripletToMatrix(add);

            }
        }
    }



    Temp.nonZeroUpdate();
    return Temp;
}

TripletMatrix TripletMatrix::operator-(const TripletMatrix &M)
{
    TripletMatrix Temp;
    Temp = *this+M.getNegMatrix();
    return Temp;
}
//destructor
//xie
TripletMatrix::~TripletMatrix()
{
    data.clear();
   //std::cout << "TripleMatrix Destructed." << '\n';
}

}//End Namespace Triple

}//End Namespace MatLib
