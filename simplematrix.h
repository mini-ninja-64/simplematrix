#ifndef simplematrix_h
#define simplematrix_h

#include <iostream>
#include <vector>


class matrix{
	public:
		void reset(int r, int c);
		void reset(int r, int c, double items[]);
		int getsetRow(int y); //if NULL row num is returned
		int getsetColumn(int x); //if NULL column num is returned
		double getsetItem(int y, int x, double item); //if NULL item is returned

		//overloads
		matrix operator+(matrix m2);
		matrix operator-(matrix m2);
		matrix operator*(matrix m2);
	private:
		int row;
		int column;
		std::vector<double> contents; //extraneous content is ignored and lacking content will be set to zero during equations
};

void matrixPrint(matrix m1);

matrix multiplyMatrix(matrix m1, matrix m2);
matrix multiplyMatrix(double sc1, matrix m1);

matrix addMatrix(matrix m1, matrix m2);

matrix subMatrix(matrix m1, matrix m2);

#endif /* simplematrix_h */