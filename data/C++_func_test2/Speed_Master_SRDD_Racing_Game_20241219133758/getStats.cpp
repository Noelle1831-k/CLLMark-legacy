string Vehicle::getStats() {
    return "Vehicle: " + name + "\nSpeed: " + to_string(maxSpeed) + "\nHandling: " + to_string(handling) + "\nBoosters: " + to_string(boosterCapacity);
}