#include <iostream>
namespace sict {

	class iProduct {

	public:
		iProduct() {};
		virtual double price() const = 0; //запрос, возвращающий цену товара
		virtual void display(std::ostream& os) const = 0; //запрос, отображающий информацию о продукте
		friend std::ostream& operator << (std::ostream& os, const iProduct& p){
			p.display(os);
			return os;
		}; // оператор, который вставляет информацию о продукте в поток os
		iProduct* readRecord(std::ifstream& file);
		~iProduct() {};
	};
}
