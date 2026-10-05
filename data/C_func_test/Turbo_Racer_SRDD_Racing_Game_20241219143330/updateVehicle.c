void updateVehicle(Vehicle* vehicle) {
    if (vehicle->fuel > 0) {
        if (vehicle->turboBoostEnabled) {
            vehicle->speed += 50;
            vehicle->fuel -= 10;
        } else {
            vehicle->speed = 100; 
        }
        vehicle->position += vehicle->speed / 10; 
    }
}