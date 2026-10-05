bool Track::hasReachedFinishLine(Vehicle* vehicle) {
    return vehicle->getPosition() >= length;
}