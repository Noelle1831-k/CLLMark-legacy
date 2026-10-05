void Vehicle::shiftGear(int newGear) {
    if (newGear >= 1 && newGear <= 5) {
        gear = newGear;
    }
}