void EventManager::searchEvents() {
    cout << "Enter event type to search for: ";
    string searchType;
    cin >> searchType;
    cout << "Searching for events of type: " << searchType << endl;
    for (int i = 0; i < events.size(); i++) {
        if (events[i].getType() == searchType) {
            events[i].viewEvent();
        }
    }
}