void freeVehicle(Vehicle *vehicle) {
    free(vehicle->name);
    free(vehicle);
}