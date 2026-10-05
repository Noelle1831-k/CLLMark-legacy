void updateVehicle(Vehicle* vehicle) {
    if (0 < vehicle->fuel) {
        if (vehicle->turboBoostEnabled) {
            vehicle->speed = vehicle->speed + 50;
            vehicle->fuel = vehicle->fuel - 10;
        } else {
            vehicle->speed = 100; 
        }
        vehicle->position = vehicle->position + vehicle->speed / 10; 
    }
}