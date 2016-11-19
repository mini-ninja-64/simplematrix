#include "simplematrix.h"

void matrixPrint(matrix m1){
	for (int y = 0; y < m1.getsetRow(NULL); y++){
		for (int x = 0; x < m1.getsetColumn(NULL); x++){
			if (x == 0){
				std::cout << "|";
			}

			std::cout << m1.getsetItem(y,x,NULL);

			if (x == m1.getsetColumn(NULL)-1){
				std::cout << "|";
			}else{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

matrix multiplyMatrix(matrix m1, matrix m2){
	//c11, c21
	//c12, c22
	matrix product;

	//check if possible
	if (m1.getsetColumn(NULL) == m2.getsetRow(NULL)){
		product.reset(m1.getsetRow(NULL), m2.getsetColumn(NULL));
		for (int i = 0; i < m2.getsetColumn(NULL); i++){
			for (int y = 0; y < m1.getsetRow(NULL); y++){
				double p = 0;
				for (int x = 0; x < m1.getsetColumn(NULL); x++){
					p+=m1.getsetItem(y,x,NULL) * m2.getsetItem(x,i,NULL);
					/*std::cout << "(" << m1.getsetItem(y,x,NULL) << " * " << m2.getsetItem(x,i,NULL) << ")";
					if (x != m1.getsetColumn(NULL)-1){
						std::cout << " + ";
					}*/
				}
				//std::cout << std::endl;
				product.getsetItem(y,i,p);
			}
		}
	}else{
		//product = NULL;
	}
	return product;
}

matrix multiplyMatrix(double sc1, matrix m1){
	matrix product;

	product.reset(m1.getsetRow(NULL), m1.getsetColumn(NULL));

	for (int y = 0; y < m1.getsetRow(NULL); y++){
		for (int x = 0; x < m1.getsetColumn(NULL); x++){
			double p = m1.getsetItem(y,x,NULL);
			product.getsetItem(y,x,p*sc1);
		}
	}

	return product;
}

matrix addMatrix(matrix m1, matrix m2){
	matrix product;
	if((m1.getsetRow(NULL) == m2.getsetRow(NULL)) && (m1.getsetColumn(NULL) == m2.getsetColumn(NULL))){
		product.reset(m1.getsetRow(NULL), m2.getsetColumn(NULL));
		for (int y = 0; y < m1.getsetRow(NULL); y++){
			for (int x = 0; x < m1.getsetColumn(NULL); x++){
				double p1 = m1.getsetItem(y,x,NULL);
				double p2 = m2.getsetItem(y,x,NULL);
				product.getsetItem(y,x,p1+p2);
			}
		}
	}else{

	}

	return product;
}

matrix subMatrix(matrix m1, matrix m2){
	matrix product;
	if((m1.getsetRow(NULL) == m2.getsetRow(NULL)) && (m1.getsetColumn(NULL) == m2.getsetColumn(NULL))){
		product.reset(m1.getsetRow(NULL), m2.getsetColumn(NULL));
		for (int y = 0; y < m1.getsetRow(NULL); y++){
			for (int x = 0; x < m1.getsetColumn(NULL); x++){
				double p1 = m1.getsetItem(y,x,NULL);
				double p2 = m2.getsetItem(y,x,NULL);
				product.getsetItem(y,x,p1-p2);
			}
		}
	}else{

	}

	return product;
}