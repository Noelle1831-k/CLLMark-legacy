double PhysicsEngine::calculateDamage(double speed, double angle) {
    return speed * cos(angle) * 0.1;
}