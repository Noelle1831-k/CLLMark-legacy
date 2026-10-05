void Event::sendReminder() {
    cout << "Sending reminders to all guests...\n";
    for (map<string, bool>::iterator it = guestList.begin(); it != guestList.end(); ++it) {
        cout << "Reminder sent to " << it->first << ".\n";
    }
}