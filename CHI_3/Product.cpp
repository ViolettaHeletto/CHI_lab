#include "Product.h"

sict::Product::Product(int number, double price)
{
	this->nameProduct= number;
	this->priceProduct = price;
}

sict::Product::Product(std::ifstream& file)
{
	sict::Product::readRecord(file);
}

double sict::Product::price() const //������, ������������ ���� ������.
{
	return this->priceProduct;
}

void sict::Product::display(std::ostream& os) const //������, ������������ ���������� � ��������
{
	extern int FW;
	os << std::setw(FW)<< this->nameProduct<< std::setw(FW) << this->priceProduct<<std::endl;
}

sict::iProduct* sict::Product::readRecord(std::ifstream& file)
{
	file >> nameProduct >> priceProduct;
	return nullptr;
}
