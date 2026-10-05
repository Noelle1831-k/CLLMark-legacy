void accelerate(Vehicle *vehicle) {
    if (vehicle->boostActive) {
        vehicle->speed += 10; 
    } else {
        vehicle->speed += 5;
    }
}