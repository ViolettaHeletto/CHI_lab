#include"ToDoList.h"

void ToDoList::addItem(ToDoItem item, std::string mess, int time)
{
	//ToDoItem item( mess, time);
	this->messageList = mess;
	this->timePointList = std::chrono::system_clock::now() + std::chrono::minutes{ time };
}

ToDoList::~ToDoList()
{
}

void ToDoList::detachCallBack()
{
	this->~ToDoList();
}
