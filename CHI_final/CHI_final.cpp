#include <stdio.h>
#include <thread>
#include <functional>
#include <iostream>
#include <mutex>
#include "ToDoItem.h"
#include"ToDoList.h"
std::mutex muut;
static void MakeNotification_thread(std::string message, int time);


int main()
{
    bool end_cin = false;
    std::string message;
    int time;
   std::thread thr_note(MakeNotification_thread, std::ref(message), time);
   
   std::cout << "Hello. Please put here your message and after qwerty time in minuts after you want have notification. If you want to end your message please put 'end 0' " << std::endl;   
    while (!end_cin) {
       
        std::cin >> message >> time;
        if(message == "end") end_cin = true;
             
    }

    thr_note.join();

    return 0;
}


static void MakeNotification_thread(std::string message, int time) {

    ToDoList newItem;
    ToDoItem Item(message, time);
    muut.lock();
    newItem.addItem(Item, std::ref(message), time);
    
    NotifierGuard quard(newItem, newItem.timePointList);
     muut.unlock();  
};
