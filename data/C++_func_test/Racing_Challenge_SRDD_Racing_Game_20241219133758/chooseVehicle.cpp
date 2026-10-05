void Player::chooseVehicle() {
    cout << name << ", select your vehicle (1: Car, 2: Bike): ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        vehicle = make_shared<Vehicle>("Car", 200);
    } else {
        vehicle = make_shared<Vehicle>("Bike", 150);
    }
    cout << name << " selected " << vehicle->getType() << " with max speed of " << vehicle->getMaxSpeed() << " km/h." << endl;
}