#include "../../include/Common/Event.h"
#include "../../include/Structures/Queue.h"

// Namespace for Event Handler
namespace EH {
    // Handles Restaurant Events
    void handleRestaurant(Event e);

    // Handles Bank Events
    void handleBank(Event e);

    // Hnadles school Events
    void handleSchool(Event e);

    // Main processing routine for Events
    void runEventHandle();

    // Processes space delimited inp, places it into parse events
    Queue<Event> getEvents(std::string inp);

    // Takes string in format: int,eventType and transforms it into event object
    Event parseEvent(std::string s);

    // Returns a progress string based on ratio to size and curr and outputs a pecent
    std::string showProgress(int size, int curr);


}