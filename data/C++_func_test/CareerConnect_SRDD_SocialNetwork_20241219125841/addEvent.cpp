void addEvent(string eventName, string eventDate) {
        CareerEvent newEvent(eventName, eventDate);
        events.push_back(newEvent);
        newEvent.createEvent();
    }