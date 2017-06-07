
#include "MatLib/TripletStore/RowLinkTriMat.h"



namespace MatLib
{

namespace TripletStore
{
RowLinkTriMat::RowLinkTriMat()
{


}
inline void RowLinkTriMat::resizeMatrix(unsigned int width, unsigned int height, unsigned int nonZero)
{
    /* TODO: Override resizeMatrix of TripletMatrix to initialize rowPtr
     * Debugged
     */
    this->matrixWidth = width; this->matrixHeight = height;
    this->nonZeroNum = nonZero;
    for(unsigned int i = 0; i <= width; i++)
    {
        this->rowPtr.push_back(0);
    }
    return;
}

void RowLinkTriMat::insertTripletToMatrix(Triplet insertTriplet)
{
    /* TODO: Insert Triplet
     * Debugged
     */
    unsigned int ins = rowPtr[insertTriplet.getRowNum()];
    unsigned int row = insertTriplet.getRowNum();

    while(!ins && row < this->getMatrixWidth())
    {

        row++; ins = rowPtr[row];
    }
    if(!ins)
    {
        this->data.push_back(insertTriplet);
        rowPtr[insertTriplet.getRowNum()] = data.size()-1;
        this->nonZeroUpdate();
        return;
    }
    else
    {
        while(ins < data.size() && data[ins].getColNum() < insertTriplet.getColNum() && data[ins].getRowNum() == row)
        {
            ins++;
        }
        if(ins < data.size() && data[ins].getColNum() == insertTriplet.getColNum() && data[ins].getRowNum() == insertTriplet.getRowNum())
        {
            std::cout << "ERROR Inserting" << '\n';
            return ;
        }
        else
        {
            this->data.insert(data.begin()+ins, insertTriplet);
            if(ins < rowPtr[insertTriplet.getRowNum()] || rowPtr[insertTriplet.getRowNum()] == 0)
            {
                rowPtr[insertTriplet.getRowNum()] = ins;
            }
            for(unsigned int i = insertTriplet.getRowNum()+1; i <= this->getMatrixWidth(); i++)
            {
                if(rowPtr[i])
                    rowPtr[i]++;
            }
            this->nonZeroUpdate();
            return;
        }
    }
    return ;
}


void RowLinkTriMat::operator=(const RowLinkTriMat &M)
{
    /*Debugged*/
    matrixWidth = M.getMatrixWidth(); matrixHeight = M.getMatrixHeight();
    nonZeroNum = M.getMatrixNonZeroNum();
    this->data.assign(M.data.begin(), M.data.end());
    this->rowPtr.assign(M.rowPtr.begin(), M.rowPtr.end());
    return;

}

RowLinkTriMat RowLinkTriMat::operator+(const RowLinkTriMat &M)
{
    if(this->matrixWidth != M.matrixWidth || this->matrixHeight != M.matrixHeight)
    {
        std::cout << "Unable To Add" << '\n';
        return *this;
    }
    RowLinkTriMat Temp; Temp.resizeMatrix(this->matrixWidth, this->matrixHeight, 0);
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
                    Temp.data.push_back(sum); i++; j++;
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
    for(unsigned int i = 0; i < Temp.data.size() - 1; i++)
    {

        if(Temp.data[i].getRowNum() != Temp.data[i+1].getRowNum())
        {
            Temp.rowPtr[Temp.data[i+1].getRowNum()] = i+1;
        }
    }
    return Temp;
}


RowLinkTriMat RowLinkTriMat::operator*(const RowLinkTriMat &M)
{
    /* TODO: Multiply
     * Debugged
     */
    RowLinkTriMat Temp;
    if(this->getMatrixHeight() != M.getMatrixWidth() || this->getMatrixWidth() == 0 || M.getMatrixHeight() == 0)
    {
        std::cout<< "ERROR in Multiplication." << '\n';
        return *this;
    }
    Temp.resizeMatrix(this->getMatrixWidth(), M.getMatrixHeight(), 0);
    //array used to store intermediate result
    std::vector<int> heightArray(M.getMatrixHeight()+1, 0);


    for(unsigned int tableRow = 1; tableRow <= this->getMatrixWidth(); tableRow++)// Each row
    {
        for(unsigned colNum = 0; colNum <= M.getMatrixHeight(); colNum++)
        {
            heightArray[colNum] = 0;
        }
        for(unsigned int j = rowPtr[tableRow]; j < this->data.size(); j++)//Traverse this Matrix data vector
        {
            if(j == 0) {break;}
            if(this->data[j].getRowNum() == tableRow)
            {
                for(unsigned int k = M.rowPtr[data[j].getColNum()]; k < M.data.size(); k++)//Traverse M data vector
                {
                    if(k == 0){break;}
                    if(this->data[j].getColNum() == M.data[k].getRowNum())
                    {
                        heightArray[M.data[k].getColNum()] += (this->data[j].getValue())*M.data[k].getValue();
                    }
                }
            }
        }
        for(unsigned int colNum = 1; colNum <= M.getMatrixHeight(); colNum++)//Transfer heightArray to Temp
        {
            if(heightArray[colNum])
            {
                Triplet add;
                add.modifyTriplet(tableRow, colNum, heightArray[colNum]);
                Temp.insertTripletToMatrix(add);

            }
        }
    }


    for(unsigned int i = 0; i < Temp.data.size() - 1; i++)
    {

        if(Temp.data[i].getRowNum() != Temp.data[i+1].getRowNum())
        {
            Temp.rowPtr[Temp.data[i+1].getRowNum()] = i+1;
        }
    }
    Temp.nonZeroUpdate();
    return Temp;
}


void RowLinkTriMat::displayTable() const
{
    /*  TODO: Override displayTable, add display of rowPtr
     *  Debugged
     */
    std::cout << "Matrix Table Print:" << '\n';
    std::cout << "Data: " << '\n';
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
    std::cout << '\n' << "rowPtr: " << '\n';
    for(unsigned int i = 1; i< rowPtr.size(); i++)
    {
        std::cout << rowPtr[i] << '\t';
    }
    std::cout << '\n';

}

RowLinkTriMat::~RowLinkTriMat()
{
    //dtor
}

}


}
