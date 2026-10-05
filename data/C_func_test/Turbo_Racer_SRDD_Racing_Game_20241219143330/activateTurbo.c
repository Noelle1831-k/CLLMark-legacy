void activateTurbo(Vehicle* vehicle) {
    if (vehicle->fuel >= 10) {
        vehicle->turboBoostEnabled = 1;
        printf("Turbo activated! Speed increased.\n");
    } else {
        printf("Not enough fuel to activate turbo!\n");
    }
}