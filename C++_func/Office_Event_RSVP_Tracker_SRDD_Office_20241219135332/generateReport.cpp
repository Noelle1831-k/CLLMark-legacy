void Event::generateReport() {
    cout << "\n--- Event Attendance Report ---\n";
    cout << "Event: " << name << "\n";
    cout << "Date: " << date << "\n";
    cout << "Time: " << time << "\n";
    cout << "Location: " << location << "\n";
    cout << "Guest List:\n";
    for (map<string, bool>::iterator it = guestList.begin(); it != guestList.end(); ++it) {
        cout << it->first << " - " << (it->second ? "Attending" : "Not Attending") << "\n";
    }
}