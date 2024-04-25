#ifndef ARRAY2D_HPP
#define ARRAY2D_HPP

template <class T> class Array2D 
{
private:
	// private data fields for number of rows and columns
	unsigned int numRows;
	unsigned int numCols;
	T* a;
	
public:
	// constructor takes 2 args: rows and columns
	Array2D(unsigned int rows, unsigned int cols);
	
	// returns element at specified row and column
	T get(int row, int col) const {return this->a[row*this->getNumCols() + col];}
	
	// returns number of rows
	int getNumRows() const {return numRows;}
	
	// returns number of columns
	int getNumCols() const {return numCols;}
	
	// sets value at row and column, return reference to invoking object
	Array2D& set(T element, int row, int col);
	
	// display array to screen
	void print() const;
	
	~Array2D();
};
	
#endif