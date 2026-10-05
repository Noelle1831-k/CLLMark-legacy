void EventManager::sendReminders() {
    cout << "Sending reminders to all attendees..." << endl;
    event.trackRSVP();
    cout << "Reminders sent successfully!" << endl;
}