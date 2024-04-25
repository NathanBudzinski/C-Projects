#ifndef ARRAY2D_CPP
#define ARRAY2D_CPP

#include <iostream>
#include "array2d.hpp"
using namespace std;

// constructor
template <class T>
Array2D<T>::Array2D(unsigned int rows, unsigned int cols)
	: numRows{rows}, numCols{cols}
{
	this->a = new T[rows*cols];
}

// implementation of the set method
template <class T>
Array2D<T>& Array2D<T>::set(T element, int row, int col)
{
	a[row*this->getNumCols() + col] = element;
	return *this;
}

template <class T>
void Array2D<T>::print() const
{
	for (int i = 0; i < this->getNumRows(); i++)
	{
		for (int j = 0; j < this->getNumCols(); j++)
		{
			cout << "[" << this->get(i, j) << "], ";
		}
		cout << endl;
	}
}

template <class T>
Array2D<T>::~Array2D()
{
	delete[] a;
}




#endif