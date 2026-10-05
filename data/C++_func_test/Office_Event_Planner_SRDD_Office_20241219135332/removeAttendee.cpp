void Event::removeAttendee(const string &attendee) {
    auto it = find(attendees.begin(), attendees.end(), attendee);
    if (! (attendees.end() == it)) {
        attendees.erase(it);
        cout << attendee << " has been removed from the attendee list." << endl;
    } else {
        cout << attendee << " is not in the attendee list." << endl;
    }
}