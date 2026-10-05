void accelerateVehicle(Vehicle *vehicle) {
    vehicle->speed += 10;
    printf("Vehicle accelerated! Current speed: %d\n", vehicle->speed);
}