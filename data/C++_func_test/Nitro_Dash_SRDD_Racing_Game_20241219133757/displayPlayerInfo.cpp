void Player::displayPlayerInfo() const {
    cout << "Player Score: " << score << endl;
    if (selectedVehicle) {
        cout << "Selected Vehicle - Speed: " << selectedVehicle->getSpeed() << ", Handling: " << selectedVehicle->getHandling() << endl;
    } else {
        cout << "No vehicle selected." << endl;
    }
}