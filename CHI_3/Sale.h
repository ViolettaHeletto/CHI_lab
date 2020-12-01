#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
#include "TaxableProduct.h"

namespace sict {

	class Sale{
public:
	 
	Sale() {};
	Sale(char* nameOfFile);// онструктор с одним аргументом, который получает адрес неизмен€емой строки
	void display(std::ostream& os) const; //
	~Sale() {};
	private:
		std::vector<sict::iProduct *> product_vect;
		
};

}