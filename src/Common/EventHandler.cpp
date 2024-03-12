#include "../../include/Common/EventHandler.h"
#include <iostream>
#include <vector>


void EH::handleRestaurant(Event e){
    std::cout << "Restaurant," << e.getInfo() << std::endl;
    e.finish();
}

void EH::handleBank(Event e){
    std::cout << "Banking," << e.getInfo() << std::endl;
    e.finish();
}

void EH::handleSchool(Event e){
    std::cout << "School," << e.getInfo() << std::endl;
    e.finish(); 
}

void EH::runEventHandle(){
    Queue<Event> eventQueue;

    std::unordered_map<Event::version, std::function<void(Event)>> eventMap;
    eventMap[Event::version::bank] = handleBank;
    eventMap[Event::version::school] = handleSchool;
    eventMap[Event::version::restaurant] = handleRestaurant;

    Dispatcher disp(eventMap);

    Event e1(42, Event::version::restaurant);
    Event e2(123, Event::version::bank);
    Event e3(144,Event::version::bank);
    Event e4(184,Event::version::school);
    Event e5(101,static_cast<Event::version>(5));
    eventQueue.enqueue(e1);
    eventQueue.enqueue(e2);
    eventQueue.enqueue(e3);
    eventQueue.enqueue(e4);
    eventQueue.enqueue(e5);
    
    while(!eventQueue.isEmpty()){
        Event e = eventQueue.dequeue();
        disp.dispatchEvent(e);
    }
    
}
