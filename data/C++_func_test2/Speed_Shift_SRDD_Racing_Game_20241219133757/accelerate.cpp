void Car::accelerate() {
    if (fuelLevel > 0) {
        speed += 5 * gear;
        if (speed > 200) speed = 200;
        consumeFuel();
    } else {
        cout << "Out of fuel! Unable to accelerate." << endl;
    }
}