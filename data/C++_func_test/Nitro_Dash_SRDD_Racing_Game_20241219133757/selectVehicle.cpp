void Player::selectVehicle(Vehicle* vehicle) {
    selectedVehicle = vehicle;
    cout << "Vehicle selected. Speed: " << vehicle->getSpeed() << ", Handling: " << vehicle->getHandling() << endl;
}