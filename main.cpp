#include <iostream>
#include "TripleMatrix.h"
//using namespace std;

using namespace MatLib::TripleStore;

int main()
{
    Triple a;
    a.displayTriple();
    a.modifyTriple(2, 2, 1);
    a.displayTriple();
    TripleMatrix mat;
    mat.createMatrix(3, 3, 3);
    mat.printMatrix();
    mat.insertTripleToMatrix(a);
    mat.printMatrix();
    a.modifyTriple(1, 2, 3);
    mat.insertTripleToMatrix(a);
    mat.printMatrix();
    a.modifyTriple(1, 1, 10);
    mat.insertTripleToMatrix(a);
    mat.printMatrix();
    mat.displayTable();
    a.modifyTriple(2, 1, 4);
    mat.insertTripleToMatrix(a);
    mat.printMatrix();
    mat.displayTable();
    a.modifyTriple(3,2,6);
    mat.insertTripleToMatrix(a);
    mat.displayTable();
    mat.printMatrix();
    return 0;
}
