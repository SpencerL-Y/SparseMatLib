#ifndef ARRAY1D_H
#define ARRAY1D_H

namespace MatLib
{

namespace ArrayStore
{

class Array1d
{
    public:
        Array1d(unsigned int length);
        virtual ~Array1d();

    protected:
        unsigned int arraySize;

    private:
};

}
}
#endif // ARRAY1D_H
