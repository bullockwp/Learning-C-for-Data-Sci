#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF
#include <cmath>
#include <iostream>
#include <cassert>
#include <vector>

template <class T>
class Vector
{
private:
    std::vector<T> mData; // data stored in vector
    int mSize; // size of vector
public:
    Vector(const Vector<T>& otherVector);
    Vector(int size);
//    ~Vector();
    int size() const;
    T& operator[](int i); // zero-based indexing
    T const& operator[] (int i)const; // zero-based indexing
    // assignment
    Vector& operator=(const Vector<T>& otherVector);
    Vector operator-() const; // unary -
    Vector operator+(const Vector<T>& v1) const; // binary +
    Vector operator-(const Vector<T>& v1) const; // binary -
    // scalar multiplication
    Vector operator*(T a) const;
    // p-norm method
    double CalculateNorm(int p=2) const;
    std::vector<T> const& getStorage() const;
};

// Overridden copy constructor
// Allocates memory for new vector, and copies
// entries of other vector into it
template <class T> Vector<T>::Vector(const Vector& otherVector)
{

    mSize = otherVector.size();
    mData.resize(mSize);
    for (int i=0; i<mSize; i++)
    {
        mData[i] = otherVector.mData[i];
    }
}

// Constructor for vector of a given size
// Allocates memory, and initialises entries
// to zero
template <class T> Vector<T>::Vector(int size)
{
    assert(size > 0);
    mSize = size;
    mData.resize(size);
    for (int i=0; i<mSize; i++)
    {
        mData[i] = 0.0;
    }
}

//// Overridden destructor to correctly free memory
//template <class T> Vector<T>::~Vector()
//{
//    delete[] mData;
//}

// Method to get the size of a vector
template <class T> int Vector<T>::size() const
{
    return mSize;
}

// Overloading square brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
template <class T> T& Vector<T>::operator[](int i)
{
    assert(i >= 0);
    assert(i < mSize);
    return mData[i];
}

// Overloading square brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
template <class T> T const& Vector<T>::operator[](int i)const{
    assert(i >= 0);
    assert(i < mSize);
    return mData[i];
}

// Overloading the assignment operator
template <class T> Vector<T>& Vector<T>::operator=(const Vector& otherVector){
    assert(mSize == otherVector.mSize);
    for (int i=0; i<mSize; i++)
    {
        mData[i] = otherVector.mData[i];
    }
    return *this;
}

// Overloading the unary - operator
template <class T> Vector<T> Vector<T>::operator-() const
{
    Vector v(mSize);
    for (int i=0; i<mSize; i++)
    {
        v[i] = -mData[i];
    }
    return v;
}

// Overloading the binary + operator
template <class T> Vector<T> Vector<T>::operator+(const Vector& v1) const
{
    assert(mSize == v1.mSize);
    Vector v(mSize);
    for (int i=0; i<mSize; i++)
    {
        v[i] = mData[i] + v1.mData[i];
    }
    return v;
}

// Overloading the binary - operator
template <class T> Vector<T> Vector<T>::operator-(const Vector& v1) const
{
    assert(mSize == v1.mSize);
    Vector v(mSize);
    for (int i=0; i<mSize; i++)
    {
        v[i] = mData[i] - v1.mData[i];
    }
    return v;
}

// Overloading scalar multiplication
template <class T> Vector<T> Vector<T>::operator*(T a) const
{
    Vector v(mSize);
    for (int i=0; i<mSize; i++)
    {
        v[i] = a*mData[i];
    }
    return v;
}

// Method to calculate norm (with default value p=2)
// corresponding to the Euclidean norm
template <class T> double Vector<T>::CalculateNorm(int p) const
{
    double norm_val, sum = 0.0;
    for (int i=0; i<mSize; i++)
    {
        sum += pow(fabs(mData[i]), p);
    }
    norm_val = pow(sum, 1.0/((double)(p)));
    return norm_val;
}

// extra: get storage to return mData

template <class T> const std::vector<T>& Vector<T>::getStorage() const
{
    return mData;
}


#endif