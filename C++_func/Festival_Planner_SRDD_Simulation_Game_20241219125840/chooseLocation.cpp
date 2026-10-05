void Player::chooseLocation(Location& location) {
    string name;
    int capacity;
    cout << "Enter the name of your festival location: ";
    cin >> name;
    cout << "Enter the capacity of your festival location: ";
    cin >> capacity;
    location = Location(name, capacity, true);
}