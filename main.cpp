#include <iostream>

using namespace std;
#include <vector>


//#include <MatLib/ArrayStore/Array1d.h>
#include <MatLib/TripletStore/TripletMatrix.h>
using namespace MatLib::TripletStore;
int main()
{
//TripletMatrix

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
    RowLinkTriMat mult  i = M+MM;
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

    return 0;
}
