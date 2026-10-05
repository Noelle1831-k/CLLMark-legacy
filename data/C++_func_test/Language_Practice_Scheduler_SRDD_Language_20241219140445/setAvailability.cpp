void User::setAvailability() {
    cout << "Enter your availability (days/times, type 'done' to finish): ";
    string timeSlot;
    for(int identifier = 1; cin >> timeSlot && ! (timeSlot == "done"); ) {
        availability.push_back(timeSlot);
    }
}