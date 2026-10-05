Vehicle* createVehicle() {
    Vehicle* vehicle = (Vehicle*)malloc(sizeof(Vehicle));
    vehicle->speed = 100;
    vehicle->turboBoostEnabled = 0;
    vehicle->fuel = 100;
    vehicle->position = 0;
    return vehicle;
}