#include"ToDoItem.h"

ToDoItem::ToDoItem(std::string mess, int time)
{
	this->message = mess;
	this->timePoint = std::chrono::system_clock::now() + std::chrono::minutes{ time };
		 
}
