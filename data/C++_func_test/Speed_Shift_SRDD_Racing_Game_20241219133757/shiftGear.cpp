void Car::shiftGear(int newGear) {
    if (newGear >= 1 && newGear <= 6) {
        gear = newGear;
        cout << "Shifted to gear: " << gear << endl;
    } else {
        cout << "Invalid gear!" << endl;
    }
}