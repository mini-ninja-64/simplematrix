#include <iostream>
#include "simplematrix.h"

int main(int argc, char const *argv[])
{
	matrix w;
	matrix x;
	matrix y;
	matrix z;

	double wCon[6] = {1,-3,2,-2,3,1};
	double xCon[9] = {3,2,1,-1,2,3,2,-1,1};
	double yCon[6] = {1,2,0,0,-1,2};
	double zCon[4] = {0,1,2,3};
	w.reset(3,2,wCon);
	x.reset(3,3,xCon);
	y.reset(2,3,yCon);
	z.reset(2,2,zCon);

	matrixPrint(w*y-x);
	std::cout << std::endl;
	matrixPrint(w*y-x);
	std::cout << std::endl;
	matrixPrint(y*w-(z*z));


	return 0;
}
