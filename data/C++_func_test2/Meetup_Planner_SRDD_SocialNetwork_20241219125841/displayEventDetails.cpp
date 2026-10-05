void Event::displayEventDetails() const {
    cout << "Event: " << title << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Location: " << location << endl;
    cout << "Interests: ";
    for (size_t i = 0; i < interests.size(); i++) {
        cout << interests[i];
        if (i < interests.size() - 1) cout << ", ";
    }
    cout << endl;
}