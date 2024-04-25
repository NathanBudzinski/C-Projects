#include <iostream>
#include "array2d.cpp"

int main()
{
	unsigned int rows;
	cout << "Enter number of rows: ";
	cin >> rows;
	unsigned int cols;
	cout << "Enter number of columns: ";
	cin >> cols;
	
	Array2D<int> arr{rows, cols};
	
	for (int i = 0; i < arr.getNumRows(); i++)
	{
		for (int j = 0; j < arr.getNumCols(); j++)
		{
			arr.set(i*j, i, j);
		}
	}
	arr.print();
	cout << "The number of rows is: " << arr.getNumRows() << endl;
	cout << "The number of columns is: " << arr.getNumCols() << endl;
}