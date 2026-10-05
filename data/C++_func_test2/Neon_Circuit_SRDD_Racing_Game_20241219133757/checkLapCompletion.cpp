bool Track::checkLapCompletion(Vehicle &vehicle) {
    return (vehicle.getX() > 90 && vehicle.getY() > 90);
}