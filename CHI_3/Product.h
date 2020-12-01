#pragma once
#include <iostream>
#include <iomanip>
#include<fstream>
#include "iProduct.h"

namespace sict {
	class Product : public iProduct {

	public:
		Product() {};
		Product(int n, double number);
		Product(std::ifstream& file);
		virtual double price() const; //запрос, возвращающий цену товара
		virtual void display(std::ostream&) const; //запрос, отображающий информацию о продукте
		virtual iProduct * readRecord(std::ifstream& file);
		~Product() {};

	private:
		double priceProduct = 0;
		int nameProduct = 0;
	};

}
