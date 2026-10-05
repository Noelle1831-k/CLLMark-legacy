Vehicle::Vehicle(string name, int maxSpeed, int handling, int boosterCapacity)
    : name(name), maxSpeed(maxSpeed), handling(handling), boosterCapacity(boosterCapacity) {
    currentSpeed = 0;
    boostersUsed = 0;
}