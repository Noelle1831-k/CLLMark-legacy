void EventScheduler::triggerEvent(const string& eventName) {
    auto it = events.find(eventName);
    if (it != events.end()) {
        cout << "Triggered event: " << eventName << " changing to wallpaper: " << it->second << endl;
    } else {
        cout << "Event not found: " << eventName << endl;
    }
}