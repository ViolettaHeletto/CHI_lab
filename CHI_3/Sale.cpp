#include "Sale.h"
#include <fstream>
#include <iomanip>
#include <math.h>

sict::Sale::Sale(char* nameOfFile)
{
	std::ifstream product_stream(nameOfFile);
	if (product_stream.is_open())
	{
		while (!product_stream.eof())
		{
			TaxableProduct temp = TaxableProduct();
			product_vect.push_back((temp.readRecord(product_stream)));
		}
	}
	product_stream.close();
}


void sict::Sale::display(std::ostream& os) const
{
	extern int FW; // using field width for output from L4.cpp
	if (!product_vect.empty())
	{
		double Total = 0;
		os << std::setw(FW) << "Product No" << std::setw(FW) << "Cost" << std::setw(FW) << "Taxable" << std::endl;
		for (size_t i = 0; i < product_vect.size(); i++)
		{
			product_vect[i]->display(os);
			Total += product_vect[i]->price();
		}
		os << std::setw(FW) << "Total" << std::setw(FW) << Total << std::endl;
	}
}
