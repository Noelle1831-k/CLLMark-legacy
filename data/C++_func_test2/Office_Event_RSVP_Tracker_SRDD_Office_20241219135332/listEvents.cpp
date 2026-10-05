void EventManager::listEvents() {
    cout << "\n--- List of Events ---\n";
    for (vector<Event>::iterator it = events.begin(); it != events.end(); ++it) {
        cout << "Event: " << it->getName() << "\n";
    }
}