#pragma once
#include <chrono>
#include <iostream>
//#include"ToDoList.h"


class ToDoItem
{

public:
    ToDoItem() {};
    ToDoItem(std::string message, int time);

    ~ToDoItem() {};

private:
    std::string message;
    std::chrono::time_point<std::chrono::system_clock> timePoint;
    
};
