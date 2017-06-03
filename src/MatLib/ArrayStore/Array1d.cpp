#include "MatLib/ArrayStore/Array1d.h"
#include <iostream>

namespace MatLib
{

namespace ArrayStore
{



Array1d::Array1d(unsigned int length)
{
    this->arraySize = length;
    //ctor
}

Array1d::~Array1d()
{
    //dtor
}
}

}
