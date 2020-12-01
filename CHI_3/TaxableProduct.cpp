#include "TaxableProduct.h"

std::string cmpStatus(std::string str, std::string temp);

sict::TaxableProduct::TaxableProduct(int name, double price, std::string status)
{
	this->nameTProduct = name;
	this->priceTProduct = price;
	this->status = status;
}

double sict::TaxableProduct::price() const
{
	float N = 100.f;
	double price = this->priceTProduct;
	if (this->status == "HST") {
		this->priceTProduct = floor((price + (price * 0.13)) * N + 0.5f) / N;
	}
	else if (this->status == "PST") {
		this->priceTProduct = floor((price + (price * 0.08)) * N + 0.5f) / N;
	}
	return this->priceTProduct;
}

void sict::TaxableProduct::display(std::ostream& os) const
{
	extern int FW;
	os << std::setw(FW) << this->nameTProduct << std::setw(FW) << this->priceTProduct<< std::setw(FW) << this->status << std::endl;
}

sict::iProduct* sict::TaxableProduct::readRecord(std::ifstream& file)
{
	int number;
	double price;
	std::string temp;
	std::string str;
	file >> number >> price;
	std::ios_base::streampos possition = file.tellg();
	file >> temp;
	if (temp.size() > 2)
	{
		file.seekg(possition);

	}

	if (temp[0] == 'H' || temp[0] == 'P')
	{		
		str = cmpStatus(str, temp);
		return new TaxableProduct(number, price, str);
	}
	return new Product(number, price);
}

std::string cmpStatus(std::string str, std::string temp) {
	
	if (temp[0] == 'H')
	{
		str = "HST";
	}
	else
	{
		str = "PST";
	}
	return str;
}