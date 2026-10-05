void Car::consumeFuel() {
    fuelLevel = fuelLevel - 0.5f;
    if (fuelLevel < 0) fuelLevel = 0;
}