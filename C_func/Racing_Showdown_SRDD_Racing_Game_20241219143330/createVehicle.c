Vehicle createVehicle(const char *name, int speed, int acceleration, int handling) {
    Vehicle vehicle;
    snprintf(vehicle.name, sizeof(vehicle.name), "%s", name);
    vehicle.speed = speed;
    vehicle.acceleration = acceleration;
    vehicle.handling = handling;
    vehicle.boostsUsed = 0;
    return vehicle;
}