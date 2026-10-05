void Event::trackRSVP() const {
    cout << "RSVP List:" << endl;
    for (const auto &attendee : attendees) {
        cout << "- " << attendee << endl;
    }
}