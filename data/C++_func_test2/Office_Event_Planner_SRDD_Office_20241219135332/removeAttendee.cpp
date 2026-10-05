void Event::removeAttendee(const string &attendee) {
    auto it = find(attendees.begin(), attendees.end(), attendee);
    if (it != attendees.end()) {
        attendees.erase(it);
        cout << attendee << " has been removed from the attendee list." << endl;
    } else {
        cout << attendee << " is not in the attendee list." << endl;
    }
}