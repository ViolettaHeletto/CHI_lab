#pragma once
#include "Product.h"
#include <string>

namespace sict
{
	class TaxableProduct : public Product
	{
	public:
		TaxableProduct() {};
		TaxableProduct(int n, double p, std::string s);
		virtual double price() const;
		virtual void display(std::ostream& os) const;
		friend  std::ostream& operator << (std::ostream& os, const TaxableProduct& p)
		{
			p.display(os);
			return os;
		};
		virtual iProduct* readRecord(std::ifstream& file);
		~TaxableProduct() {};

	private:
		int nameTProduct = 0;
		mutable double priceTProduct = 0;
		std::string status;
	};
}
		