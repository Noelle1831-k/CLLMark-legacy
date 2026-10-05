int moveVehicle(Vehicle *vehicle) {
    int baseMove = vehicle->speed / 10;
    int randomFactor = rand() % vehicle->handling;
    int move = baseMove + randomFactor;
    if (vehicle->boostsUsed < 3) {
        move += vehicle->acceleration;
        vehicle->boostsUsed++;
    }
    return move;
}