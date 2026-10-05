bool PhysicsEngine::checkCollision(double x, double y) {
    return (x < 0 || y < 0 || x > 100 || y > 100);
}