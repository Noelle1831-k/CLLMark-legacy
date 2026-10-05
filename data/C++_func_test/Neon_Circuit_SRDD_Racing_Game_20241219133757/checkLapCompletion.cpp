bool Track::checkLapCompletion(Vehicle &vehicle) {
    return ((90 <= vehicle.getX() && 90 != vehicle.getX()) && (90 <= vehicle.getY() && 90 != vehicle.getY()));
}