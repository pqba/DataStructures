#ifndef EVENT_H
#define EVENT_H

#include <chrono>
#include <functional>
#include <stdexcept>
#include <unordered_map>

// Event with an integer representing information, specified version enum, initial timestamp, and handle status.
class Event {
   private:
    time_t timestamp;  // Time reference: https://en.cppreference.com/w/cpp/chrono/time_point/time_since_epoch
    bool handled;
    int information;

   public:
    // Define version enum class
    enum class version {
        none,
        bank,
        school,
        restaurant,
    };

    std::string names[4] = {"NONE", "bank", "school", "restaurant"};  // Maps version number to actual enun names.

    const static int names_len = 4;

    version ver;

    Event(int info, version ver)
        : timestamp(std::chrono::system_clock::now().time_since_epoch().count()), handled(false), information(info), ver(ver) {}

    Event() : timestamp(0), handled(true), information(0), ver(version::none) {}

    version getVersion() const {
        return ver;
    }
    const std::string print() {
        return names[static_cast<int>(ver)] + " " + std::to_string(timestamp) + " " + std::to_string(information) + " " + std::to_string(handled);
    }
    int getInfo() const {
        return information;
    }
    void finish() {
        handled = true;
    }
};

// Dispatcher for Events, mapping event versions to functions
class Dispatcher {
   private:
    std::unordered_map<Event::version, std::function<void(Event)>> eventHandler;

   public:
    Dispatcher() = default;
    Dispatcher(std::unordered_map<Event::version, std::function<void(Event)>> ehandle) {
        for (auto &it : ehandle) {
            registerEventHandler(it.first, it.second);
        }
    }

    void registerEventHandler(Event::version eventType, const std::function<void(Event)> &handler) {
        eventHandler[eventType] = handler;
    }

    void dispatchEvent(const Event &e) {
        auto handlefunc = eventHandler.find(e.getVersion());
        if (handlefunc != eventHandler.end()) {
            handlefunc->second(e);
        } else {
            std::string dispatchErr = "No handler found for event type: ";
            dispatchErr += std::to_string(static_cast<int>(e.getVersion()));
            throw std::invalid_argument(dispatchErr);
        }
    }
};

#endif
