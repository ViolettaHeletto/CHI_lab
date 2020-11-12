#include "TXT.h"

namespace l1 {
	Txt::Txt()
	{
	}

	Txt::Txt(const std::string &Name)
	{
		std::ifstream ifs(Name, std::ios::in);
		if (!ifs) {
			arr = NULL;
			ifs.close();
		}
		else {
			/*Если файл существует, конструктор с одним аргументом выделяет память для количества строк, содержащихся в файле, и копирует их в память. */
			int count = 0;
			std::string help;
			while (getline(ifs, help)) {
				count++;
			}
			NumberOfStrings = count;
			ifs.clear();
			ifs.seekg(0);
			arr = new std::string[NumberOfStrings];

			for (int i = 0; i < NumberOfStrings; i++) {
				ifs >> arr[i];
			}
			ifs.close();
		}
	
	}

	Txt::Txt(const Txt& NameOfCopy)
	{
		NumberOfStrings = NameOfCopy.NumberOfStrings;
		arr = new std::string[NumberOfStrings];
		for (int i = 0; i < NumberOfStrings; i++) {
			arr[i] = NameOfCopy.arr[i];
		}
	}

	Txt& Txt::operator=(const Txt& NameOfCopy)
	{
		if (&NameOfCopy == this) {
			return *this;
		}
		else {
			if (arr) {
				delete[] arr;
			}
			NumberOfStrings = NameOfCopy.NumberOfStrings;
			arr = new std::string[NumberOfStrings];
			for (int i = 0; i < NumberOfStrings; i++) {
				arr[i] = NameOfCopy.arr[i];
			}
		}
		return *this;
	}

	Txt::Txt(Txt&& NameOfMove)
	{
		NumberOfStrings = NameOfMove.NumberOfStrings;
		arr = new std::string[NumberOfStrings];
		for (int i = 0; i < NumberOfStrings; i++) {
			arr[i] = NameOfMove.arr[i];
		}
		NameOfMove.arr = nullptr;
		NameOfMove.NumberOfStrings = 0;

	}

	Txt& Txt::operator = (Txt &&NameOfMove)
	{
		if (&NameOfMove == this) {
			return *this;
		}
		else {
			if (arr) {
				delete[] arr;
			}
			NumberOfStrings = NameOfMove.NumberOfStrings;
			arr = new std::string[NumberOfStrings];
			for (int i = 0; i < NumberOfStrings; i++) {
				arr[i] = NameOfMove.arr[i];
			}
			NameOfMove.arr = nullptr;
			NameOfMove.NumberOfStrings = 0;
		}
		return *this;
	}

	Txt::~Txt()
	{
		delete[]arr;
	}

	size_t const Txt::size() {

		return this->NumberOfStrings;
	}

}