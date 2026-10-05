void PhysicsEngine::handleCollisions(Car &car, Track &track) {
    for (size_t i = 0; i < track.getObstacles().size(); i++) {
        if (abs(car.getPosition() - track.getObstacles()[i].getPosition()) < 1.0f) {
            track.getObstacles()[i].interact(car);
        }
    }
}