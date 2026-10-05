void User::displayJoinedEvents() const {
    cout << "Events joined by " << name << ":" << endl;
    for (size_t i = 0; i < joinedEvents.size(); i++) {
        cout << "- " << joinedEvents[i].getTitle() << endl;
    }
}