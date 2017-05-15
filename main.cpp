#include <iostream>
#include "TripleMatrix.h"
//using namespace std;

using namespace MatLib::TripleStore;

int main()
{
    Triple a;
    Triple b;
    a.displayTriple();
    a.modifyTriple(2, 2, 1);
    a.displayTriple();
    TripleMatrix mat;
    TripleMatrix what;
    what.createMatrix(3,3,3);
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
    //mat.destroyMatrix();
    mat.displayTable();

    //what.displayTable();
    what.printMatrix();

    b = a;
    //b.displayTriple();
    a+b;

    b.modifyTriple(3,3,9);
    what.insertTripleToMatrix(b);
    b.modifyTriple(1,2,19);
    what.insertTripleToMatrix(b);
    what.printMatrix();
    what.displayTable();
    mat = mat+what;
    mat.displayTable();
    mat.printMatrix();
    std::cout << mat.getMatrixNonZeroNum() << '\n';
    //std::cout << (what == mat) << '\n';
    return 0;
}
