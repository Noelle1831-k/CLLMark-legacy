void Player::chooseLocation(Location& location) {
    string name;
    int capacity;
    printf("Enter the name of your festival location: ");
    cin >> name;
    printf("Enter the capacity of your festival location: ");
    cin >> capacity;
    location = Location(name, capacity, true);
}