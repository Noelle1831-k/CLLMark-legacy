void EventManager::listEvents() {
    cout << "Listing all events:" << endl;
    for (int i = 0; i < events.size(); i++) {
        events[i].viewEvent();
    }
}