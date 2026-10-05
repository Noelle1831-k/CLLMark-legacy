CareerEvent(string eventName, string eventDate) {
        this->eventID = generateUniqueID();
        this->eventName = eventName;
        this->eventDate = eventDate;
    }