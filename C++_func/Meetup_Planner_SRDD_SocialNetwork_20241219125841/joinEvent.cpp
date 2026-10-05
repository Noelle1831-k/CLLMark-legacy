void User::joinEvent(const Event& event) {
    joinedEvents.push_back(event);
    cout << name << " joined the event: " << event.getTitle() << endl;
}