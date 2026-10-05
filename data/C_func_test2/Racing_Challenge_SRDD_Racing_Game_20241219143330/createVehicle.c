Vehicle *createVehicle(const char *name, int maxSpeed, int acceleration, int handling) {
    Vehicle *vehicle = (Vehicle *)malloc(sizeof(Vehicle));
    vehicle->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(vehicle->name, name);
    vehicle->maxSpeed = maxSpeed;
    vehicle->acceleration = acceleration;
    vehicle->handling = handling;
    return vehicle;
}