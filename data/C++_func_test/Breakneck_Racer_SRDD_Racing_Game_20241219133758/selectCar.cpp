void Player::selectCar(Car &car) {
    selectedCar = &car;
    cout << name << " selected car: " << car.getName() << endl;
}