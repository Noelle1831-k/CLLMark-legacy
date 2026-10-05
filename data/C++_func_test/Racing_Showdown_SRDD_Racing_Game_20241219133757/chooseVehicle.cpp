void Player::chooseVehicle() {
    cout << "Choose your vehicle: " << endl;
    cout << "1. Speedster (High Speed, Low Handling)" << endl;
    cout << "2. Tank (Low Speed, High Handling)" << endl;
    cout << "3. Balanced (Medium Speed and Handling)" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            vehicle = Vehicle("Speedster", 200, 5, 3);
            break;
        case 2:
            vehicle = Vehicle("Tank", 120, 10, 8);
            break;
        case 3:
            vehicle = Vehicle("Balanced", 150, 7, 5);
            break;
        default:
            cout << "Invalid choice! Defaulting to Balanced." << endl;
            vehicle = Vehicle("Balanced", 150, 7, 5);
            break;
    }
}