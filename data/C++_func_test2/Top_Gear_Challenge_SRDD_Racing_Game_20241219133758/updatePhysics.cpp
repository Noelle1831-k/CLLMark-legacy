void PhysicsEngine::updatePhysics(Car& car, const Track& track) {
    if (car.getPosition() > track.getTrackLength()) {
        cout << "Collision detected! Resetting car position.\n";
        car.applyBrakes();
    }
}