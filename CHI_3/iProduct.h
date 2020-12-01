#include <iostream>
namespace sict {

	class iProduct {

	public:
		iProduct() {};
		virtual double price() const = 0; //������, ������������ ���� ������
		virtual void display(std::ostream& os) const = 0; //������, ������������ ���������� � ��������
		friend std::ostream& operator << (std::ostream& os, const iProduct& p){
			p.display(os);
			return os;
		}; // ��������, ������� ��������� ���������� � �������� � ����� os
		iProduct* readRecord(std::ifstream& file);
		~iProduct() {};
	};
}
