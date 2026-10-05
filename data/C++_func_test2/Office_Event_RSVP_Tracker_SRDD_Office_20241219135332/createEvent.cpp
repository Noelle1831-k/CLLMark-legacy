void EventManager::createEvent(string name, string date, string time, string location) {
    events.push_back(Event(name, date, time, location));
    cout << "Event " << name << " created successfully.\n";
}