bool Track::checkCollision(Vehicle &vehicle) {
    float x = vehicle.getX();
    float y = vehicle.getY();
    return (x < 0 || y < 0 || x > 100 || y > 100);
}