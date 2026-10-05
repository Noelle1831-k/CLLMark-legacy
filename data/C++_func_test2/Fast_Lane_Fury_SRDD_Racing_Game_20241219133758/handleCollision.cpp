void PhysicsEngine::handleCollision(Car &car) {
    cout << "Collision detected! Reducing speed." << endl;
    car.brake();
}