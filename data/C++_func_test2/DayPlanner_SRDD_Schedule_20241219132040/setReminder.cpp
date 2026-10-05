void Notification::setReminder(string message, int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
    cout << "Reminder: " << message << endl;
}