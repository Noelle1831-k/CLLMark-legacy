void PhysicsEngine::applyPhysics(Car &car) {
    car.updatePosition();
    if (car.isColliding()) {
        handleCollision(car);
    }
}