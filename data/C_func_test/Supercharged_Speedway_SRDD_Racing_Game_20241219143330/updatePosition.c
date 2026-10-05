void updatePosition(Vehicle *vehicle) {
    vehicle->position += vehicle->speed;
    if (vehicle->boostActive) {
        vehicle->boostActive = 0; 
    }
}