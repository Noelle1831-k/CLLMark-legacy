double PhysicsEngine::calculateTime(const Car& car, const Track& track) {
    double averageSpeed = (car.getTopSpeed() + car.getAcceleration() * 2) / 2;
    double speedFactor = 1.0 + car.getHandling() * 0.2;
    averageSpeed *= speedFactor;
    if (car.getNitroBoosts() > 0) {
        averageSpeed *= 1.2;
    }
    return track.getLength() / averageSpeed;
}