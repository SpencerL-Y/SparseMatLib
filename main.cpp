#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#include <vector>
#include <memory>
#include <MatLib/TripletStore/RowLinkTriMat.h>
#include <MatLib/ArrayStore/Array1d.h>
#include <MatLib/TripletStore/TripletMatrix.h>
#include <MatLib/CrossListStore/CLNode.h>
#include <MatLib/CrossListStore/CLMatrix.h>
#include <MatLib/ArrayStore/Array2d.h>
#include <MatLib/CSRStore/CSRMatrix.h>
using namespace MatLib::CSRStore;
int main(int argc,char *argv[])
{
//TripletMatrix
/*
    TripletMatrix M;
    cout << M.data[0].getValue();
    M.resizeMatrix(3,3,3);
    cout << M.getMatrixHeight() << M.getMatrixWidth() << M.getMatrixNonZeroNum();
    Triplet a;
    a.modifyTriplet(1,1,1);
    M.insertTripletToMatrix(a);
    a.modifyTriplet(1,2,1);
    M.insertTripletToMatrix(a);
    a.modifyTriplet(2,1,1);
    M.insertTripletToMatrix(a);
    a.modifyTriplet(1,3,1);
    M.insertTripletToMatrix(a);
    M.nonZeroUpdate();
    std::cout << '\n';
    M.displayTable();
    M.printMatrix();
    TripletMatrix temp;
    temp = M;

    a.modifyTriplet(2,3,1);
    temp.insertTripletToMatrix(a);
    temp.printMatrix();
    (temp+M).printMatrix();
    TripletMatrix my = temp.getNegMatrix();
    my.printMatrix();
    (my*temp).printMatrix();
    (my*temp).transposeMatrix().printMatrix();
    */
//vector
/*
    vector<int> vec(4);
    vec[0] = 1; vec[1] = 2; vec[2] = 3; vec[3] = 4;
    vec.insert(vec.begin()+1, 10);
    vec.resize(3,0);
    for(int i =0; i< vec.size();i++)
    {
        cout << vec[i];
    }
*/
//RowLinkTriMat
/*
    RowLinkTriMat M;
    M.resizeMatrix(3,3,3);
    M.displayTable();
    Triplet a; a.modifyTriplet(1,1,1);
    M.insertTripletToMatrix(a);
    M.displayTable();
    a.modifyTriplet(2,2,2); M.insertTripletToMatrix(a);
    M.displayTable();
    a.modifyTriplet(3,3,3); M.insertTripletToMatrix(a);
    M.displayTable();
    RowLinkTriMat MM; MM.resizeMatrix(3,3,0);
    a.modifyTriplet(2,3,1); MM.insertTripletToMatrix(a);
    MM.displayTable();
    a.modifyTriplet(3,1,2); MM.insertTripletToMatrix(a);
    MM.displayTable();
    MM.printMatrix();
    (M+MM).displayTable();
    (M+MM).printMatrix();
    RowLinkTriMat multi = M+MM;
    (multi*multi).displayTable();
    (multi*multi).printMatrix();
*/
//Array1d
/*
    Array1d ary1(6,1);
    Array1d ary2(6,1);
    for(unsigned int i = 1; i <= ary1.getSize(); i++)
    {
        ary1.elemAssign(i, 2);
        ary2.elemAssign(i, 1);
    }
    ary1.arrayPrint();
    ary2.arrayPrint();
    std::cout << ary1.dotProduct(ary2);
    ary1.transpose();
    ary1.arrayPrint();
*/
//Array2d
/*
    Array2d M(3,3);
    M.printMatrix();
    M.insertElem(1,1,1); M.insertElem(2,2,2);
    M.insertElem(2,3,1);M.insertElem(3,3,4);
    M.printMatrix();
    M.getNegMatrix().transpose().printMatrix();
    Array2d temp;
    temp = (M.transpose());
    temp.printMatrix();
    std::cout << temp.getNonZeroNum() << '\n';
    (temp*M).printMatrix();
    (temp - M).printMatrix();
    */
//STD array

//CLNode
/*
    CLNode N1(1,1,1);
    CLNode N2(1,1,1);
    shared_ptr<CLNode> temp;


    N1.createDownNode(1,2,1);
    N1.printDownList();
    temp = N1.down;
    temp->createDownNode(1,3,2);
    N1.printDownList();
    N1.deleteDownNode();
    N1.printDownList();
    N1.modifyNode(3,3,3);
    N1.printDownList();


    N2.createRightNode(1,2,1);
    N2.printRightList();
    temp = N2.right;
    temp->createRightNode(1,3,2);
    N2.printRightList();
    N2.deleteRightNode();
    N2.printRightList();
    CLNode head1;
    std::shared_ptr<CLNode> what;
    what = std::make_shared<CLNode>(12,12,12);
    what->createRightNode(13,13,13);
    what->printRightList();


    std::shared_ptr<CLNode> head; head = std::make_shared<CLNode>(1,0,0);
    head->createRightNode(1,3,2); head->right->createRightNode(1,5,2);
    head->printRightListVal(6);*/
//CLMatrix

    CLMatrix M(3,3,3);
    for(unsigned int i = 0; i < 4; i++)
    {
        std::cout << (M.rowHead[i]->getColNum()) << '\t' << (M.colHead[i]->getRowNum()) << '\n';
    }
    std::cout << M.getWidth() << '\t' << M.getHeight() << '\t' << M.getNonZero() << '\n';
    CLNode ins(1,1,1);
    M.insertNode(ins);
    ins.modifyNode(1,2,1);
    M.insertNode(ins);
    ins.modifyNode(2,1,1);
    M.insertNode(ins);
    ins.modifyNode(2,3,1);
    M.insertNode(ins);
    M.printMatrix();
    CLMatrix Mprime;
    Mprime = M;
    ins.modifyNode(3,3,1);
    Mprime.insertNode(ins);
    ins.modifyNode(3,3,-1);
    M.insertNode(ins);
    Mprime.printMatrix();
    M.printMatrix();
    std::cout << (M == Mprime);
    (M+Mprime).printMatrix();
    (M*Mprime).printMatrix();
    M = (M*Mprime);
    M.printMatrix();
    M.getNegMat().printMatrix();
    Mprime.printMatrix();
    (M-Mprime).printMatrix();
    CLMatrix test(5,5,5);
    for(unsigned int i = 1; i <=5; i++)
    {
        for(unsigned int j = 5; j >=1; j--)
        {

        }
    }
    //CSRMatrix
    /*
    CSRMatrix mat(4, 4);
    for(unsigned int i = 1; i <=4; i ++)
    {
        for(unsigned int j = 1; j <=4; j++)
        {
            mat.insertElemToMat(i,j,10);
        }
    }
    mat.displayTable();
    mat.printMatrix();
    CSRMatrix amat(3,3);
    amat = mat;

    CSRTuple ins; ins.modifyTuple(2,2);
    amat.insertElemToMat(4,4,1);amat.displayTable();amat.printMatrix();
    amat.addInsert(1,ins);
    amat.printMatrix();
    (amat+mat).printMatrix();
    std::cout << (amat == mat);
    mat.printMatrix();
    (amat-mat).printMatrix();
    */
    /*

    if(argc == 2)
    {
        if(!strcmp(argv[1], "-help"))
        {
            std::cout << "Usage:" << " print SML -n or SML -n -v" << endl;
        }

        if(!strcmp(argv[1], "-n"))
        {
            std::cout << "first test" << endl;
        }
    }
    if(argc == 3)
    {
        if(!strcmp(argv[1], "-n") && !strcmp(argv[2], "-v"))
        {
            std::cout << "second test" << endl;
        }
    }
*/

    return 0;
}

