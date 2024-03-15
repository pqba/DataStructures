#include "../../include/Common/EventHandler.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

// Implementations from header file.

void EH::handleRestaurant(Event e) {
    std::cout << "Restaurant," << e.getInfo() << std::endl;
    e.finish();
}

void EH::handleBank(Event e) {
    std::cout << "Banking," << e.getInfo() << std::endl;
    e.finish();
}

void EH::handleSchool(Event e) {
    std::cout << "School," << e.getInfo() << std::endl;
    e.finish(); 
}

Queue<Event> EH::getEvents(std::string userInput) {
    Queue<Event> combined;
    std::stringstream eventStream(userInput);
    while(eventStream.good()) {
        std::string foundEvent; 
        std::getline(eventStream,foundEvent,' ');
        Event createdEvent = parseEvent(foundEvent);
        combined.enqueue(createdEvent);
    }
    return combined;
}

Event EH::parseEvent(std::string s) {
    if(s == "" || s.length() < 3){
        throw std::invalid_argument("Length of string too small.");
    }
    if(s.find(',') == std::string::npos || std::count(s.begin(),s.end(),',') != 1){
        throw std::invalid_argument("Unacceptable data format. Incorrect amount of commas.");
    }
    std::string number = s.substr(0,s.find(','));
    // Number checking.
    int N;
    try {
        N = std::stoi(number);
    }
    catch(const std::invalid_argument&e) {
        throw std::invalid_argument("Invalid number format for event.");
    }
    catch(const std::out_of_range &e) {
        throw std::invalid_argument("Length of number (integer) too large.");    
    }
    // Event checking
    std::string eventName = s.substr(s.find(',')+1);
    Event e;
    for(int i = 0; i <  Event::names_len; i++){
        std::string v_nm = e.names[i];
        if(strcasecmp(v_nm.c_str(),eventName.c_str()) == 0) {
            // Sucessful!
            Event created = Event(N,static_cast<Event::version>(i));
            return created;
        }
    }
    throw std::invalid_argument("No event version found with that name.");
}

void EH::runEventHandle(){
    Queue<Event> eventQueue;

    std::unordered_map<Event::version, std::function<void(Event)>> eventMap;
    eventMap[Event::version::bank] = handleBank;
    eventMap[Event::version::school] = handleSchool;
    eventMap[Event::version::restaurant] = handleRestaurant;

    Dispatcher disp(eventMap);

    std::cout << "Welcome to Event Handler.\nEvent Types: Restaurant, Bank, School, Restaurant" << std::endl;
    while(true) {
        std::cout << "Enter event type and data in format -> integer,type and seperate events by spaces. Otherwise, enter 'Q' to quit: ";
        std::string input;
        std::getline(std::cin,input);
        std::cout << std::endl;
        if(strcasecmp(input.c_str(),"Q") == 0){
            break;
        }
        if(!input.empty()){
            Queue<Event> newEvents = getEvents(input);
            eventQueue.extend(newEvents);
        }

        while(!eventQueue.isEmpty()){
            Event toRemove = eventQueue.dequeue();
            disp.dispatchEvent(toRemove);
        }
    }
    std::cout << "Leaving Event Handler. Goodbye!" << std::endl;
}
