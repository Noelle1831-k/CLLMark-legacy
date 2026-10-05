void Vehicle::shiftGear(int newGear) {
    if (1 <= newGear && newGear <= 5) {
        gear = newGear;
    }
}