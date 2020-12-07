#pragma once
#include"ToDoItem.h"
#include <thread>
#include <mutex>


class ToDoList
{
public:
    ToDoList() {};
    /* you can change the signature,
    but the item should be passed as cheaper as possible (only ctor, no copy)
    also this function should be thread safe*/
    void addItem(ToDoItem item, std::string message, int time);
    std::chrono::time_point<std::chrono::system_clock> timePointList;

    ~ToDoList();
//protected:   dosn`t work with protected
    /* this function should be thread safe */
    template<typename F>
    void setCallbackNotifier(F callback);
    void detachCallBack();
    std::string messageList;
    

};

class NotifierGuard : ToDoList
{
public:
    ToDoList list;
    template<typename F>
    NotifierGuard(ToDoList& list_, F callback){
        list.setCallbackNotifier(callback);
    };
    ~NotifierGuard() {
        detachCallBack();
    };
};

template<typename F>
inline void ToDoList::setCallbackNotifier(F callback)
{
    //muut.lock();
    if (std::chrono::system_clock::now() == callback)
    {
        std::cout << this->messageList;
   }
    //muut.unlock();
}
