#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#include <vector>
#include <memory>
#include <MatLib/TripletStore/RowLinkTriMat.h>
#include <MatLib/ArrayStore/Array1d.h>
#include <MatLib/TripletStore/Triplet.h>
#include <MatLib/TripletStore/TripletMatrix.h>
#include <MatLib/CrossListStore/CLNode.h>
#include <MatLib/CrossListStore/CLMatrix.h>
#include <MatLib/ArrayStore/Array2d.h>
#include <MatLib/CSRStore/CSRMatrix.h>
using namespace MatLib;

void printHelp();
void guide();
void array1dDot();
void array1dAdd();
void array1dTrans();
void array2dTrans();
void array2dMult();
void array2dAdd();
void array2dSub();
void triTrans();
void triAdd();
void triSub();
void triMult();
void clmAdd();
void clmMult();
void clmSub();
void csrMult();
void csrSub();
void csrAdd();
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
    RowLinkTriMat test;
    test.resizeMatrix(5,5,5);
    for(unsigned int i = 1; i<=5; i++)
    {
        for(unsigned int j = 5; j >=1; j--)
        {
            Triplet ins; ins.modifyTriplet(i,j,10);
            test.insertTripletToMatrix(ins);
        }
    }
    test.printMatrix();
    test.displayTable();*/
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
/*
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
            CLNode ins(i,j,10);
            test.insertNode(ins);
        }
    }
    test.printMatrix();*/
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
    CSRMatrix a(3,3);
    a.insertElemToMat(1,1,1);
    a.insertElemToMat(1,3,2);
    a.insertElemToMat(3,2,1);
    CSRMatrix b(3,3);
    b.insertElemToMat(3,1,1);
    b.insertElemToMat(2,2,1);
    b.insertElemToMat(1,3,1);
    a.printMatrix();
    b.printMatrix();
    (a*b).printMatrix();
    */
    if(argc == 1)
    {
        printHelp();
    }

    if(argc == 2 )
    {
        if(!strcmp(argv[1], "-help"))
        {
            printHelp();
        }
        else
        {
            guide();
        }
    }
    if(argc == 3)
    {
        if(!strcmp(argv[1], "-ary1d"))
        {
            if(!strcmp(argv[2], "-dot"))
            {
                array1dDot();
            }
            else if(!strcmp(argv[2], "-add"))
            {
                array1dAdd();
            }
            else if(!strcmp(argv[2], "-trs"))
            {
                array1dTrans();
            }
            else
            {
                std::cout << "invalid argument:" << argv[2] << '\n';
                guide();
            }
        }
        else if(!strcmp(argv[1], "-ary2d"))
        {
            if(!strcmp(argv[2],"-trs"))
            {
                array2dTrans();
            }
            else if(!strcmp(argv[2], "-mmult"))
            {
                array2dMult();
            }
            else if(!strcmp(argv[2], "-add"))
            {
                array2dAdd();
            }
            else if(!strcmp(argv[2], "-sub"))
            {
                array2dSub();
            }
            else
            {
                guide();
            }
        }
        else if(!strcmp(argv[1], "-clm"))
        {
            if(!strcmp(argv[2], "-add"))
            {
                clmAdd();
            }
            else if(!strcmp(argv[2], "-sub"))
            {
                clmSub();
            }
            else if(!strcmp(argv[2], "-mmult"))
            {
                clmMult();
            }
            else
            {
                guide();
            }
        }
        else if(!strcmp(argv[1], "-tri"))
        {
            if(!strcmp(argv[2], "-add"))
            {
                triAdd();
            }
            else if(!strcmp(argv[2], "-sub"))
            {
                triSub();
            }
            else if(!strcmp(argv[2], "-mmult"))
            {
                triMult();
            }
            else if(!strcmp(argv[2], "-trs"))
            {
                triTrans();
            }
            else
            {
                guide();
            }
        }
        else if(!strcmp(argv[1], "-csr"))
        {
            if(!strcmp(argv[2], "-mmult"))
            {
                csrMult();
            }
            else if(!strcmp(argv[2], "-sub"))
            {
                csrSub();
            }
            else if(!strcmp(argv[2], "-add"))
            {
                csrAdd();
            }
            else
            {
                guide();
            }
        }
        else
        {
            guide();
        }
    }
    else
    {
        guide();
    }

    return 0;
}


void printHelp()
{
std::cout << "Usage:" << " SML [-formats] [-options]" << endl;
        std::cout <<'\t'<<"Formats" << '\t' << "Options" <<'\t' << " Descriptions "<< '\n';
        std::cout << '\n';
        std::cout << '\t' << "-ary1d" << '\t'<< '\t' << "Class Array1d:" << '\n'
                  << '\t' << '\t'<< "-dot" << '\t' << "dot product of two arrays." << '\n'
                  << '\t' << '\t'<< "-add" << '\t' << "addition of of two arrays." << '\n'
                  << '\t' << '\t'<< "-trs" << '\t' << "array transpose: print the transpose of the vector" << '\n' << '\n'
                  << '\t' << "-ary2d" <<  '\t'<< '\t' << "Class Array2d:" <<'\n'
                  << '\t' << '\t'<< "-mmult" << '\t' << "output the multiplication of two matrices" << '\n'
                  << '\t' << '\t'<< "-add" << '\t' << "addition of of two matrices." << '\n'
                  << '\t' << '\t'<< "-sub" << '\t' << "subtraction of of two matrices." << '\n' << '\n'
                  << '\t' << '\t'<< "-trs" << '\t' << "matrix transpose: print the transpose of the matrix" << '\n'
                  << '\t' << "-tri" <<  '\t'<< '\t' << "Class TripletMatrix:" <<'\n'
                  << '\t' << '\t'<< "-trs" << '\t' << "matrix transpose: print the transpose of the matrix" << '\n'
                  << '\t' << '\t'<< "-mmult" << '\t' << "output the multiplication of two matrices" << '\n'
                  << '\t' << '\t'<< "-add" << '\t' << "addition of of two matrices." << '\n'
                  << '\t' << '\t'<< "-sub" << '\t' << "subtraction of of two matrices." << '\n' << '\n'
                  << '\t' << "-trirl" <<  '\t'<< '\t' << "Class RowLinkTriMat:" <<'\n'
                  << '\t' << '\t'<< "-trs" << '\t' << "matrix transpose: print the transpose of the matrix" << '\n'
                  << '\t' << '\t'<< "-mmult" << '\t' << "output the multiplication of two matrices" << '\n'
                  << '\t' << '\t'<< "-add" << '\t' << "addition of of two matrices." << '\n'
                  << '\t' << '\t'<< "-sub" << '\t' << "subtraction of of two matrices." << '\n' << '\n'
                  << '\t' << "-clm" <<  '\t'<< '\t' << "Class CLMatrix:" <<'\n'
                  << '\t' << '\t'<< "-mmult" << '\t' << "output the multiplication of two matrices" << '\n'
                  << '\t' << '\t'<< "-add" << '\t' << "addition of of two matrices." << '\n'
                  << '\t' << '\t'<< "-sub" << '\t' << "subtraction of of two matrices." << '\n' << '\n'
                  << '\t' << "-csr" <<  '\t'<< '\t' << "Class CSRMatrix:" <<'\n'
                  << '\t' << '\t'<< "-mmult" << '\t' << "output the multiplication of two matrices" << '\n'
                  << '\t' << '\t'<< "-add" << '\t' << "addition of of two matrices." << '\n'
                  << '\t' << '\t'<< "-sub" << '\t' << "subtraction of of two matrices." << '\n' << '\n';
}

void guide()
{
    std::cout << "Usage:" << " SML [-formats] [-options]" << endl;
    std::cout << "where [-formats] can be:" << '\n'
              << "-ary1d, -ary2d, -tri, -trirl, -clm, -csr" << '\n'
              << "Or use 'SML -help' to get detailed description." << '\n';
}

void array1dDot()
{
    std::cout << "input the length of vectors:" << '\n';
    int length; cin >> length;
    std::cout << "Are they row vectors? (Y/N)" << '\n';
    char input; cin >> input;
    int rowVector;
    if(input == 'Y' || input == 'y' || input == '1'){rowVector = 1;}
    else if(input == 'N' || input == 'n'|| input == '0'){rowVector = 0;}
    else {std::cout << "ERROR input."; return;}
    ArrayStore::Array1d myArray1(length, rowVector);
    ArrayStore::Array1d myArray2(length, rowVector);
    std::cout << "input elements for array1 (format: '1 2 3'):" << '\n';
    for(unsigned int i = 1; i < myArray1.vec.size(); i++)
    {
        cin >> myArray1.vec[i];
    }
    std::cout << "input elements for array2 (format: '1 2 3'):" << '\n';
    for(unsigned int i = 1; i < myArray2.vec.size(); i++)
    {
        cin >> myArray2.vec[i];
    }
    std::cout << "the result is: " << myArray1.dotProduct(myArray2);
}

void array1dAdd()

{
    std::cout << "input the length of vectors:" << '\n';
    int length; cin >> length;
    std::cout << "Are they row vectors? (Y/N)" << '\n';
    char input; cin >> input;
    int rowVector;
    if(input == 'Y' || input == 'y' || input == '1'){rowVector = 1;}
    else if(input == 'N' || input == 'n'|| input == '0'){rowVector = 0;}
    else {std::cout << "ERROR input."; return;}
    ArrayStore::Array1d myArray1(length, rowVector);
    ArrayStore::Array1d myArray2(length, rowVector);
    std::cout << "input elements for array1 (format: '1 2 3'):" << '\n';
    for(unsigned int i = 1; i < myArray1.vec.size(); i++)
    {
        cin >> myArray1.vec[i];
    }
    std::cout << "input elements for array2 (format: '1 2 3'):" << '\n';
    for(unsigned int i = 1; i < myArray2.vec.size(); i++)
    {
        cin >> myArray2.vec[i];
    }
    std::cout << "the addition result is: " << '\n' ;
    (myArray1+myArray2).arrayPrint();
}


void array1dTrans()
{
    std::cout << "input the length of vector:" << '\n';
    int length; cin >> length;
    std::cout << "is it a row vector? (Y/N)" << '\n';
    char input; cin >> input;
    int rowVector;
    if(input == 'Y' || input == 'y' || input == '1'){rowVector = 1;}
    else if(input == 'N' || input == 'n'|| input == '0'){rowVector = 0;}
    else {std::cout << "ERROR input."; return;}
    ArrayStore::Array1d myArray1(length, rowVector);
    std::cout << "input elements for array1 (format: '1 2 3'):" << '\n';
    for(unsigned int i = 1; i < myArray1.vec.size(); i++)
    {
        cin >> myArray1.vec[i];
    }
    std::cout << "result of transpose is: " << '\n' ;
    myArray1.transpose();
    myArray1.arrayPrint();
}


void array2dTrans()
{
    std::cout << "input the row number and col number of the matrix:" << '\n'
              << "row: " << '\n';

    int width; int height;
    cin >> width; std::cout << "col: " <<'\n';cin >> height;
    ArrayStore::Array2d myArray2d(width, height);
    std::cout << "input the number of nonzero elements:" << '\n';
    unsigned int nznum; cin >> nznum;
    std::cout << "input non-zero elements (in the format: 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nznum; i++)
    {
        unsigned int row, col, val;
        std::cout << i <<"th:" << '\n';
        cin >> row >> col >> val;
        if(myArray2d.data[row][col]){std::cout << "element exists" << '\n'; i--; continue;}
        myArray2d.data[row][col] = val;

    }
    std::cout << "original matrix: " << '\n';
    myArray2d.printMatrix();
    std::cout << "transposed matrix: " << '\n';
    myArray2d.transpose().printMatrix();
}
void array2dMult()
{
    std::cout << "input the row number and col number of two matrices:" << '\n'<<"first: "
              << "row: ";

    int width1; int height1;cin >> height1;
    std::cout << "col: " ;cin >> width1;std::cout <<"second: " << "row: " ;
    int width2; int height2;cin >> width2;std::cout << "col: "; cin>>height2;
    ArrayStore::Array2d myArray2d1(width1, height1);
    ArrayStore::Array2d myArray2d2(width2, height2);
    if(width1 != height2){std::cout << "ERROR: size incompatible." <<'\n';return;}
    std::cout << "input the number of nonzero elements:" << '\n';
    std::cout << "first: " << '\n';unsigned int nznum1; cin >> nznum1;
    std::cout << "second: " << '\n';unsigned int nznum2; cin >> nznum2;
    std::cout << "input non-zero elements (in the format: 'row col val'):" << '\n';
    std::cout << "first: " << '\n';
    for(unsigned int i = 1; i <= nznum1; i++)
    {
        unsigned int row, col, val;
        std::cout << i <<"th:" << '\n';
        cin >> row >> col >> val;
        if(myArray2d1.data[row][col]){std::cout << "element exists" << '\n'; i--; continue;}
        myArray2d1.data[row][col] = val;

    }
    std::cout << "second: " << '\n';
    for(unsigned int i = 1; i <= nznum2; i++)
    {
        unsigned int row, col, val;
        std::cout << i <<"th:" << '\n';
        cin >> row >> col >> val;
        if(myArray2d2.data[row][col]){std::cout << "element exists" << '\n'; i--; continue;}
        myArray2d2.data[row][col] = val;

    }
    std::cout << "original matrix: " << '\n';
    std::cout << "first: " << '\n';
    myArray2d1.printMatrix();
    std::cout << "second: " << '\n';
    myArray2d2.printMatrix();
    std::cout << "multiplication result: " << '\n';
    (myArray2d1*myArray2d2).printMatrix();
}
void array2dAdd()
{
    std::cout << "input the row number and col number of two matrices:" << '\n'<<"first: "
              << "row: ";

    int width1; int height1;cin >> height1;
    std::cout << "col: ";cin >> width1;std::cout <<"second: " << "row: ";
    int width2; int height2;cin >> width2;std::cout << "col: "; cin>>height2;
    ArrayStore::Array2d myArray2d1(width1, height1);
    ArrayStore::Array2d myArray2d2(width2, height2);
    if(width1 != height2){std::cout << "ERROR: size incompatible." <<'\n';return;}
    std::cout << "input the number of nonzero elements:" << '\n';
    std::cout << "first: " << '\n';unsigned int nznum1; cin >> nznum1;
    std::cout << "second: " << '\n';unsigned int nznum2; cin >> nznum2;
    std::cout << "input non-zero elements (in the format: 'row col val'):" << '\n';
    std::cout << "first: " << '\n';
    for(unsigned int i = 1; i <= nznum1; i++)
    {
        unsigned int row, col, val;
        std::cout << i <<"th:" << '\n';
        cin >> row >> col >> val;
        if(myArray2d1.data[row][col]){std::cout << "element exists" << '\n'; i--; continue;}
        myArray2d1.data[row][col] = val;

    }
    std::cout << "second: " << '\n';
    for(unsigned int i = 1; i <= nznum2; i++)
    {
        unsigned int row, col, val;
        std::cout << i <<"th:" << '\n';
        cin >> row >> col >> val;
        if(myArray2d2.data[row][col]){std::cout << "element exists" << '\n'; i--; continue;}
        myArray2d2.data[row][col] = val;

    }
    std::cout << "original matrix: " << '\n';
    std::cout << "first: " << '\n';
    myArray2d1.printMatrix();
    std::cout << "second: " << '\n';
    myArray2d2.printMatrix();
    std::cout << "multiplication result: " << '\n';
    (myArray2d1+myArray2d2).printMatrix();
}
void array2dSub()
{
std::cout << "input the row number and col number of two matrices:" << '\n'<<"first: "
              << "row: ";

    int width1; int height1;cin >> height1;
    std::cout << "col: " <<'\n';cin >> width1;std::cout <<"second: " << "row: ";
    int width2; int height2;cin >> width2;std::cout << "col: "; cin>>height2;
    ArrayStore::Array2d myArray2d1(width1, height1);
    ArrayStore::Array2d myArray2d2(width2, height2);
    if(width1 != height2){std::cout << "ERROR: size incompatible." <<'\n';return;}
    std::cout << "input the number of nonzero elements:" << '\n';
    std::cout << "first: " << '\n';unsigned int nznum1; cin >> nznum1;
    std::cout << "second: " << '\n';unsigned int nznum2; cin >> nznum2;
    std::cout << "input non-zero elements (in the format: 'row col val'):" << '\n';
    std::cout << "first: " << '\n';
    for(unsigned int i = 1; i <= nznum1; i++)
    {
        unsigned int row, col, val;
        std::cout << i <<"th:" << '\n';
        cin >> row >> col >> val;
        if(myArray2d1.data[row][col]){std::cout << "element exists" << '\n'; i--; continue;}
        myArray2d1.data[row][col] = val;

    }
    std::cout << "second: " << '\n';
    for(unsigned int i = 1; i <= nznum2; i++)
    {
        unsigned int row, col, val;
        std::cout << i <<"th:" << '\n';
        cin >> row >> col >> val;
        if(myArray2d2.data[row][col]){std::cout << "element exists" << '\n'; i--; continue;}
        myArray2d2.data[row][col] = val;

    }
    std::cout << "original matrix: " << '\n';
    std::cout << "first: " << '\n';
    myArray2d1.printMatrix();
    std::cout << "second: " << '\n';
    myArray2d2.printMatrix();
    std::cout << "multiplication result: " << '\n';
    (myArray2d1-myArray2d2).printMatrix();
}


void triTrans()
{
    std::cout << "input the row and col number of the matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the number of non-zero elements: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    TripletStore::TripletMatrix myTriMat1;
    myTriMat1.resizeMatrix(rowNum1, colNum1, nonz1);
    std::cout << "input the non-zero elements (in the format 'row col val')" << '\n';
    for(unsigned int i = 1; i <= nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        TripletStore::Triplet ins; ins.modifyTriplet(row, col, val);
        myTriMat1.insertTripletToMatrix(ins);
    }
    std::cout << "original matrix: " << '\n';
    myTriMat1.printMatrix();
    std::cout << "transposed matrix: " << '\n';
    myTriMat1.transposeMatrix().printMatrix();
}
void triAdd()
{
    std::cout << "input the row and col number of the first matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the row and col number of the second matrix: " << '\n'
              << "row: ";
    unsigned int rowNum2; cin >> rowNum2;
    std::cout << "col: ";
    unsigned int colNum2; cin >> colNum2;
    std::cout << "input the non-zero number of the first matrix: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    std::cout << "input the non-zero number of the second matrix: " << '\n';
    unsigned int nonz2; cin >> nonz2;
    TripletStore::TripletMatrix myTriMat1;
    myTriMat1.resizeMatrix(rowNum1, colNum1, nonz1);
    TripletStore::TripletMatrix myTriMat2;
    myTriMat2.resizeMatrix(rowNum2, colNum2, nonz2);
    std::cout << "input the non-zero elements of first matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        TripletStore::Triplet ins; ins.modifyTriplet(row, col, val);
        myTriMat1.insertTripletToMatrix(ins);
    }
    std::cout << "input the non-zero elements of second matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz2; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        TripletStore::Triplet ins; ins.modifyTriplet(row, col, val);
        myTriMat2.insertTripletToMatrix(ins);
    }
    std::cout << "original matrices: " << '\n';
    std::cout << "first: " << '\n'; myTriMat1.printMatrix();
    std::cout << "second: " << '\n'; myTriMat2.printMatrix();
    std::cout << "addition result: " << '\n';
    (myTriMat1+myTriMat2).printMatrix();
}
void triSub()
{
std::cout << "input the row and col number of the first matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the row and col number of the second matrix: " << '\n'
              << "row: ";
    unsigned int rowNum2; cin >> rowNum2;
    std::cout << "col: ";
    unsigned int colNum2; cin >> colNum2;
    std::cout << "input the non-zero number of the first matrix: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    std::cout << "input the non-zero number of the second matrix: " << '\n';
    unsigned int nonz2; cin >> nonz2;
    TripletStore::TripletMatrix myTriMat1;
    myTriMat1.resizeMatrix(rowNum1, colNum1, nonz1);
    TripletStore::TripletMatrix myTriMat2;
    myTriMat2.resizeMatrix(rowNum2, colNum2, nonz2);
    std::cout << "input the non-zero elements of first matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        TripletStore::Triplet ins; ins.modifyTriplet(row, col, val);
        myTriMat1.insertTripletToMatrix(ins);
    }
    std::cout << "input the non-zero elements of second matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz2; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        TripletStore::Triplet ins; ins.modifyTriplet(row, col, val);
        myTriMat2.insertTripletToMatrix(ins);
    }
    std::cout << "original matrices: " << '\n';
    std::cout << "first: " << '\n'; myTriMat1.printMatrix();
    std::cout << "second: " << '\n'; myTriMat2.printMatrix();
    std::cout << "subtraction result: " << '\n';
    (myTriMat1-myTriMat2).printMatrix();
}
void triMult()
{
    std::cout << "input the row and col number of the first matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the row and col number of the second matrix: " << '\n'
              << "row: ";
    unsigned int rowNum2; cin >> rowNum2;
    std::cout << "col: ";
    unsigned int colNum2; cin >> colNum2;
    std::cout << "input the non-zero number of the first matrix: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    std::cout << "input the non-zero number of the second matrix: " << '\n';
    unsigned int nonz2; cin >> nonz2;
    TripletStore::TripletMatrix myTriMat1;
    myTriMat1.resizeMatrix(rowNum1, colNum1, nonz1);
    TripletStore::TripletMatrix myTriMat2;
    myTriMat2.resizeMatrix(rowNum2, colNum2, nonz2);
    std::cout << "input the non-zero elements of first matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        TripletStore::Triplet ins; ins.modifyTriplet(row, col, val);
        myTriMat1.insertTripletToMatrix(ins);
    }
    std::cout << "input the non-zero elements of second matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz2; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        TripletStore::Triplet ins; ins.modifyTriplet(row, col, val);
        myTriMat2.insertTripletToMatrix(ins);
    }
    std::cout << "original matrices: " << '\n';
    std::cout << "first: " << '\n'; myTriMat1.printMatrix();
    std::cout << "second: " << '\n'; myTriMat2.printMatrix();
    std::cout << "multiplication result: " << '\n';
    (myTriMat1*myTriMat2).printMatrix();
}


void clmAdd()
{
    std::cout << "input the row and col number of the first matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the row and col number of the second matrix: " << '\n'
              << "row: ";
    unsigned int rowNum2; cin >> rowNum2;
    std::cout << "col: ";
    unsigned int colNum2; cin >> colNum2;
    std::cout << "input the non-zero number of the first matrix: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    std::cout << "input the non-zero number of the second matrix: " << '\n';
    unsigned int nonz2; cin >> nonz2;
    CrossListStore::CLMatrix myCLM1(rowNum1, colNum1, nonz1);
    CrossListStore::CLMatrix myCLM2(rowNum2, colNum2, nonz2);
    std::cout << "input the non-zero elements of first matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCLM1.insertNode(row, col, val);
    }
    std::cout << "input the non-zero elements of second matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz2; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCLM2.insertNode(row, col, val);
    }
    std::cout << "original matrices: " << '\n';
    std::cout << "first: " << '\n'; myCLM1.printMatrix();
    std::cout << "second: " << '\n'; myCLM2.printMatrix();
    std::cout << "addition result: " << '\n';
    (myCLM1+myCLM2).printMatrix();
}
void clmMult()
{
    std::cout << "input the row and col number of the first matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the row and col number of the second matrix: " << '\n'
              << "row: ";
    unsigned int rowNum2; cin >> rowNum2;
    std::cout << "col: ";
    unsigned int colNum2; cin >> colNum2;
    std::cout << "input the non-zero number of the first matrix: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    std::cout << "input the non-zero number of the second matrix: " << '\n';
    unsigned int nonz2; cin >> nonz2;
    CrossListStore::CLMatrix myCLM1(rowNum1, colNum1, nonz1);
    CrossListStore::CLMatrix myCLM2(rowNum2, colNum2, nonz2);
    std::cout << "input the non-zero elements of first matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <=nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCLM1.insertNode(row, col, val);
    }
    std::cout << "input the non-zero elements of second matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz2; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCLM2.insertNode(row, col, val);
    }
    std::cout << "original matrices: " << '\n';
    std::cout << "first: " << '\n'; myCLM1.printMatrix();
    std::cout << "second: " << '\n'; myCLM2.printMatrix();
    std::cout << "multiplication result: " << '\n';
    (myCLM1*myCLM2).printMatrix();
}
void clmSub()
{
    std::cout << "input the row and col number of the first matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the row and col number of the second matrix: " << '\n'
              << "row: ";
    unsigned int rowNum2; cin >> rowNum2;
    std::cout << "col: ";
    unsigned int colNum2; cin >> colNum2;
    std::cout << "input the non-zero number of the first matrix: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    std::cout << "input the non-zero number of the second matrix: " << '\n';
    unsigned int nonz2; cin >> nonz2;
    CrossListStore::CLMatrix myCLM1(rowNum1, colNum1, nonz1);
    CrossListStore::CLMatrix myCLM2(rowNum2, colNum2, nonz2);
    std::cout << "input the non-zero elements of first matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCLM1.insertNode(row, col, val);
    }
    std::cout << "input the non-zero elements of second matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz2; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCLM2.insertNode(row, col, val);
    }
    std::cout << "original matrices: " << '\n';
    std::cout << "first: " << '\n'; myCLM1.printMatrix();
    std::cout << "second: " << '\n'; myCLM2.printMatrix();
    std::cout << "subtraction result: " << '\n';
    (myCLM1-myCLM2).printMatrix();
}

void csrMult()
{
    std::cout << "input the row and col number of the first matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the row and col number of the second matrix: " << '\n'
              << "row: ";
    unsigned int rowNum2; cin >> rowNum2;
    std::cout << "col: ";
    unsigned int colNum2; cin >> colNum2;
    std::cout << "input the non-zero number of the first matrix: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    std::cout << "input the non-zero number of the second matrix: " << '\n';
    unsigned int nonz2; cin >> nonz2;
    CSRStore::CSRMatrix myCSR1(rowNum1, colNum1);
    CSRStore::CSRMatrix myCSR2(rowNum2, colNum2);
    std::cout << "input the non-zero elements of first matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCSR1.insertElemToMat(row, col, val);
    }
    std::cout << "input the non-zero elements of second matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz2; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCSR2.insertElemToMat(row, col, val);
    }
    std::cout << "original matrices: " << '\n';
    std::cout << "first: " << '\n'; myCSR1.printMatrix();
    std::cout << "second: " << '\n'; myCSR2.printMatrix();
    std::cout << "multiplication result: " << '\n';
    (myCSR1*myCSR2).printMatrix();
}
void csrSub()
{
    std::cout << "input the row and col number of the first matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the row and col number of the second matrix: " << '\n'
              << "row: ";
    unsigned int rowNum2; cin >> rowNum2;
    std::cout << "col: ";
    unsigned int colNum2; cin >> colNum2;
    std::cout << "input the non-zero number of the first matrix: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    std::cout << "input the non-zero number of the second matrix: " << '\n';
    unsigned int nonz2; cin >> nonz2;
    CSRStore::CSRMatrix myCSR1(rowNum1, colNum1);
    CSRStore::CSRMatrix myCSR2(rowNum2, colNum2);
    std::cout << "input the non-zero elements of first matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCSR1.insertElemToMat(row, col, val);
    }
    std::cout << "input the non-zero elements of second matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz2; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCSR2.insertElemToMat(row, col, val);
    }
    std::cout << "original matrices: " << '\n';
    std::cout << "first: " << '\n'; myCSR1.printMatrix();
    std::cout << "second: " << '\n'; myCSR2.printMatrix();
    std::cout << "subtraction result: " << '\n';
    (myCSR1-myCSR2).printMatrix();
}
void csrAdd()
{
std::cout << "input the row and col number of the first matrix: " << '\n'
              << "row: ";
    unsigned int rowNum1; cin >> rowNum1;
    std::cout << "col: ";
    unsigned int colNum1; cin >> colNum1;
    std::cout << "input the row and col number of the second matrix: " << '\n'
              << "row: ";
    unsigned int rowNum2; cin >> rowNum2;
    std::cout << "col: ";
    unsigned int colNum2; cin >> colNum2;
    std::cout << "input the non-zero number of the first matrix: " << '\n';
    unsigned int nonz1; cin >> nonz1;
    std::cout << "input the non-zero number of the second matrix: " << '\n';
    unsigned int nonz2; cin >> nonz2;
    CSRStore::CSRMatrix myCSR1(rowNum1, colNum1);
    CSRStore::CSRMatrix myCSR2(rowNum2, colNum2);
    std::cout << "input the non-zero elements of first matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz1; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCSR1.insertElemToMat(row, col, val);
    }
    std::cout << "input the non-zero elements of second matrix (in the format 'row col val'):" << '\n';
    for(unsigned int i = 1; i <= nonz2; i++)
    {
        cout << i <<"th: ";
        unsigned int row; unsigned int col; int val;
        cin >> row >> col >> val;
        myCSR2.insertElemToMat(row, col, val);
    }
    std::cout << "original matrices: " << '\n';
    std::cout << "first: " << '\n'; myCSR1.printMatrix();
    std::cout << "second: " << '\n'; myCSR2.printMatrix();
    std::cout << "addition result: " << '\n';
    (myCSR1+myCSR2).printMatrix();
}

