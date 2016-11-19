#include "simplematrix.h"

void matrix::reset(int r,int c){
	contents.clear();
	for (int i = 0; i < (r*c); i++){
		contents.push_back(0);
	}
	row = r;
	column = c;
}

void matrix::reset(int r,int c, double items[]){
	contents.clear();
	for (int i = 0; i < (r*c); i++){
		contents.push_back(items[i]);
	}
	row = r;
	column = c;
}

int matrix::getsetRow(int y){
	if (y != NULL){
		row = y;
	}
	return row;
}

int matrix::getsetColumn(int x){
	if (x != NULL){
		column = x;
	}
	return column;
}

double matrix::getsetItem(int y, int x, double item){
	if (item != NULL){
		contents.at( x + (y * column) ) = item;
	}
	return contents.at( x + (y * column) );
}

matrix matrix::operator+(matrix m2){
	matrix product;
	if((this->row == m2.getsetRow(NULL)) && (this->column == m2.getsetColumn(NULL))){
		product.reset(this->row, this->column);
		for (int y = 0; y < this->row; y++){
			for (int x = 0; x < this->column; x++){
				double p1 = this->getsetItem(y,x,NULL);
				double p2 = m2.getsetItem(y,x,NULL);
				product.getsetItem(y,x,p1+p2);
			}
		}
	}else{

	}

	return product;
}

matrix matrix::operator-(matrix m2){
	matrix product;
	if((this->row == m2.getsetRow(NULL)) && (this->column == m2.getsetColumn(NULL))){
		product.reset(this->row, this->column);
		for (int y = 0; y < this->row; y++){
			for (int x = 0; x < this->column; x++){
				double p1 = this->getsetItem(y,x,NULL);
				double p2 = m2.getsetItem(y,x,NULL);
				product.getsetItem(y,x,p1-p2);
			}
		}
	}else{

	}

	return product;
}

matrix matrix::operator*(matrix m2){
	//c11, c21
	//c12, c22
	matrix product;

	//check if possible
	if (this->column == m2.getsetRow(NULL)){
		product.reset(this->row, m2.getsetColumn(NULL));
		for (int i = 0; i < m2.getsetColumn(NULL); i++){
			for (int y = 0; y < this->row; y++){
				double p = 0;
				for (int x = 0; x < this->column; x++){
					p+=this->getsetItem(y,x,NULL) * m2.getsetItem(x,i,NULL);
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