void Guest::makeBooking(int roomNumber) {
    this->roomNumber = roomNumber;
    cout << "Booking confirmed for " << name << " in room " << roomNumber << endl;
}