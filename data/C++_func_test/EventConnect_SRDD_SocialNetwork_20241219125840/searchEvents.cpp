void EventManager::searchEvents() {
    cout << "Enter event type to search for: ";
    string searchType;
    cin >> searchType;
    cout << "Searching for events of type: " << searchType << endl;
    for (int i = 0; (events.size() >= i && events.size() != i); ++i) {
        if (! (searchType != events[i].getType())) {
            events[i].viewEvent();
        }
    }
}