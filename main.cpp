#include <iostream>

using namespace std;
#include <vector>
#include <memory>
#include <MatLib/TripletStore/RowLinkTriMat.h>
#include <MatLib/ArrayStore/Array1d.h>
#include <MatLib/TripletStore/TripletMatrix.h>
#include <MatLib/CrossListStore/CLNode.h>
#include <MatLib/CrossListStore/CLMatrix.h>
using namespace MatLib::CrossListStore;
int main()
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
    Array1d ary1(6);
    Array1d ary2(6);
    for(unsigned int i = 1; i <= ary1.getSize(); i++)
    {
        ary1.elemAssign(i, 2*i);
        ary2.elemAssign(i, i+2);
    }
    ary1.arrayPrint();
    ary2.arrayPrint();
    std::cout << ary1.dotProduct(ary2);
*/
//CLNode

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
    head->printRightListVal(6);
//CLMatrix
/*
    CLMatrix M(3,3,3);
    for(unsigned int i = 0; i < 4; i++)
    {
        std::cout << (M.rowHead[i]->getColNum()) << '\t' << (M.colHead[i]->getRowNum()) << '\n';
    }
    std::cout << M.getWidth() << '\t' << M.getHeight() << '\t' << M.getNonZero() << '\n';
    CLNode ins(1,1,1);
    M.insertNode(ins);
*/
    return 0;
}

