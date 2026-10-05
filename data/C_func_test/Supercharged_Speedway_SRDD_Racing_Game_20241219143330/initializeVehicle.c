void initializeVehicle(Vehicle *vehicle, int speed, int ability) {
    vehicle->speed = speed;
    vehicle->specialAbility = ability;
    vehicle->position = 0;
    vehicle->boostActive = 0;
}