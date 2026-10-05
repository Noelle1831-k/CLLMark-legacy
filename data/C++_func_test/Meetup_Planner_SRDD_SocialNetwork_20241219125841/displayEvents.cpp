void MeetupManager::displayEvents() const {
    cout << "Available Events:" << endl;
    for (size_t i = 0; i < events.size(); i++) {
        events[i].displayEventDetails();
    }
}