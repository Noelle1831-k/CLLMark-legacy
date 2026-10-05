void EventScheduler::removeEvent(const string& eventName) {
    if (events.erase(eventName)) {
        cout << "Removed event: " << eventName << endl;
    } else {
        cout << "Event not found: " << eventName << endl;
    }
}