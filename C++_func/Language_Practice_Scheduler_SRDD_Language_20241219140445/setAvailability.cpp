void User::setAvailability() {
    cout << "Enter your availability (days/times, type 'done' to finish): ";
    string timeSlot;
    while (cin >> timeSlot && timeSlot != "done") {
        availability.push_back(timeSlot);
    }
}