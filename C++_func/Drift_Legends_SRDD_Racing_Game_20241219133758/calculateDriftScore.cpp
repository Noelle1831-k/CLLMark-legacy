double PhysicsEngine::calculateDriftScore(double speed, double angle, double handling) {
    return speed * sin(angle) * handling * 10;
}