void PhysicsEngine::applyGravity(Car &car) {
    float speed = car.getSpeed();
    if (speed > 0) {
        car.setPosition(car.getPosition() - 0.1f);
        cout << "Gravity applied to car: " << car.getName() << ", Speed reduced slightly." << endl;
    }
}