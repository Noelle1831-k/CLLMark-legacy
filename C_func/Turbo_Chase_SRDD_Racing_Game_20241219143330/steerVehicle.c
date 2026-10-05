void steerVehicle(Vehicle *vehicle) {
    vehicle->agility += 5;
    printf("Vehicle steered! Current agility: %d\n", vehicle->agility);
}