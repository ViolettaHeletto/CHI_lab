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
		virtual double price() const; //������, ������������ ���� ������
		virtual void display(std::ostream&) const; //������, ������������ ���������� � ��������
		virtual iProduct * readRecord(std::ifstream& file);
		~Product() {};

	private:
		double priceProduct = 0;
		int nameProduct = 0;
	};

}
