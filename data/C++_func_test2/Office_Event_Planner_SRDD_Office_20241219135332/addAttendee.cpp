void Event::addAttendee(const string &attendee) {
    attendees.push_back(attendee);
    cout << attendee << " has been added to the attendee list." << endl;
}