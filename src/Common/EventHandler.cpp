#include "../../include/Common/EventHandler.h"

#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <vector>

bool compareStrings(const std::string& v_nm, const std::string& eventName) {
    if (v_nm.length() != eventName.length()) {
        return false;
    }
    for (size_t i = 0; i < v_nm.length(); ++i) {
        if (tolower(v_nm[i]) != tolower(eventName[i])) {
            return false;
        }
    }
    return true;
}

// Display progress bar
std::string EH::showProgress(int original, int curr) {
    std::string s;
    for (int i = 0; i < curr; i++) {
        s += "#";
    }
    for (int i = curr; i < original; i++) {
        s += "-";
    }

    std::string percent = std::to_string(static_cast<int>((static_cast<float>(curr) / original) * 100));
    return s + " " + percent + "%\n";
}
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
    while (eventStream.good()) {
        std::string foundEvent;
        std::getline(eventStream, foundEvent, ' ');
        Event createdEvent = parseEvent(foundEvent);
        combined.enqueue(createdEvent);
    }
    return combined;
}

Event EH::parseEvent(std::string s) {
    if (s == "" || s.length() < 3) {
        throw std::invalid_argument("Length of string too small.");
    }
    if (s.find(',') == std::string::npos || (s.find(',') != s.rfind(','))) {
        throw std::invalid_argument("Unacceptable data format. Incorrect amount of commas.");
    }
    std::string number = s.substr(0, s.find(','));
    // Number checking.
    int N;
    try {
        N = std::stoi(number);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Invalid number format for event.");
    } catch (const std::out_of_range& e) {
        throw std::invalid_argument("Length of number (integer) too large.");
    }
    // Event checking
    std::string eventName = s.substr(s.find(',') + 1);
    Event e;
    for (int i = 0; i < Event::names_len; i++) {
        std::string v_nm = e.names[i];
        if (compareStrings(v_nm, eventName)) {
            // Sucessful!
            Event created = Event(N, static_cast<Event::version>(i));
            return created;
        }
    }
    throw std::invalid_argument("No event version found with that name.");
}

bool orderPriority() {
    std::string input;
    std::cout << "Priority order: Bank, School, Restaurant. Would you like the Events sorted by priority? (y/n): ";
    std::cin >> input;
    for (char& c : input) {
        c = std::tolower(c);
    }
    return (input == "y" || input == "yes");
}

void EH::runEventHandle() {
    Queue<Event> eventQueue;

    std::unordered_map<Event::version, std::function<void(Event)>> eventMap;
    eventMap[Event::version::bank] = handleBank;
    eventMap[Event::version::school] = handleSchool;
    eventMap[Event::version::restaurant] = handleRestaurant;
    Dispatcher disp(eventMap);

    while (true) {
        std::cout << "Enter event type and data in format -> integer,type and seperate events by spaces. Otherwise, enter 'Q' to quit: ";

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string input;
        std::getline(std::cin, input);
        std::cout << std::endl;
        if (compareStrings(input, "Q")) {
            break;
        }
        if (!input.empty()) {
            Queue<Event> newEvents = getEvents(input);
            eventQueue.extend(newEvents);
        }
        int progress = 0;
        int originalSize = eventQueue.size();

        while (!eventQueue.isEmpty()) {
            std::cout << showProgress(originalSize, progress) << std::endl;
            Event toRemove = eventQueue.dequeue();
            disp.dispatchEvent(toRemove);
            progress++;
        }
        std::cout << showProgress(originalSize, progress) << std::endl;
    }
    std::cout << "Leaving Event Handler. Goodbye!" << std::endl;
}
