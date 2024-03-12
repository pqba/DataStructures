#include "../../include/Common/Event.h"
#include "../../include/Structures/Queue.h"

#pragma once

namespace EH {

    // Declare functions
    void handleRestaurant(Event e);
    void handleBank(Event e);
    void handleSchool(Event e);
    void runEventHandle();

} // namespace eh