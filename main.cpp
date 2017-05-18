#include <iostream>
#include "TripleMatrix.h"
#include "CRSMatrix.h"
//using namespace std;

using namespace MatLib::TripleStore;

int main()
{
    /*Triple a;
    Triple b;
    TripleMatrix mat1;
    TripleMatrix mat2;
    mat1.createMatrix(3,3,3);
    mat2.createMatrix(3,3,3);
    a.modifyTriple(1,1,2);
    mat1.insertTripleToMatrix(a);
    a.modifyTriple(1,2,4);
    mat1.insertTripleToMatrix(a);
    a.modifyTriple(2,3,1);
    mat1.insertTripleToMatrix(a);
    a.modifyTriple(2,1,3);
    mat2.insertTripleToMatrix(a);
    a.modifyTriple(1,1,3);
    mat2.insertTripleToMatrix(a);
    a.modifyTriple(3,2,1);
    mat2.insertTripleToMatrix(a);
    mat1.printMatrix();
    mat1.displayTable();
    mat2.printMatrix();
    mat2.displayTable();
    TripleMatrix result;
    result.createMatrix(3,3,0);
    result = mat1*mat2;
    result.printMatrix();
    result.displayTable();*/

    CSRTuple a;
    a.modifyTuple(1,1);
    a.printTuple();
    a.destroyTuple();
    a.printTuple();
    return 0;
}
