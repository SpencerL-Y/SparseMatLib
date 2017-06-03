 #include <iostream>

using namespace std;
#include <vector>


#include "MatLib/TripletStore/TripletMatrix.h"
#include "MatLib/CSRStore/CSRMatrix.h"
using namespace MatLib::TripletStore;
int main()
{
    /*Triplet a;
    Triplet b;
    TripletMatrix mat1;
    TripletMatrix mat2;
    mat1.createMatrix(3,3,3);
    mat2.createMatrix(3,3,3);
    a.modifyTriplet(1,1,2);
    mat1.insertTripletToMatrix(a);
    a.modifyTriplet(1,2,4);
    mat1.insertTripletToMatrix(a);
    a.modifyTriplet(2,3,1);
    mat1.insertTripletToMatrix(a);
    a.modifyTriplet(2,1,3);
    mat2.insertTripletToMatrix(a);
    a.modifyTriplet(1,1,3);
    mat2.insertTripletToMatrix(a);
    a.modifyTriplet(3,2,1);
    mat2.insertTripletToMatrix(a);
    mat1.printMatrix();
    mat1.displayTable();
    mat2.printMatrix();
    mat2.displayTable();
    TripletMatrix result;
    result.createMatrix(3,3,0);
    result = mat1*mat2;
    result.printMatrix();
    result.displayTable();*/

    /*CSRTuple a;
    a.modifyTuple(1,1);
    a.printTuple();
    a.destroyTuple();
    a.printTuple();
    return 0;*/
    /*CSRMatrix M;
    CSRTuple a;
    M.createCSRMatrix(3,3);
    a.modifyTuple(1,1);
    M.insertTupleToMatrix(1,a);
    M.displayTable();
    a.modifyTuple(3,3);
    M.insertTupleToMatrix(1,a);
    M.displayTable();
    a.modifyTuple(2,2);
    M.insertTupleToMatrix(1,a);
    M.displayTable();
    a.modifyTuple(2,2);
    M.insertTupleToMatrix(3,a);
    M.displayTable();
    a.modifyTuple(1,12);
    M.insertTupleToMatrix(2,a);
    M.displayTable();
    M.printMatrix();
    //std::cout << (M == M);
    */
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
    //std::cout << (temp == M);
    /*vector<int> vec(4);
    vec[0] = 1; vec[1] = 2; vec[2] = 3; vec[3] = 4;
    vec.insert(vec.begin()+1, 10);
    for(int i =0; vec[i];i++)
    {
        cout << vec[i];
    }
*/
    return 0;
}
