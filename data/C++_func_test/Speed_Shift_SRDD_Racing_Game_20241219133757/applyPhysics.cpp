void PhysicsEngine::applyPhysics(Car &car, const Track &track) {
    float drag = 0.1f;
    car.accelerate();
    car.updatePosition(1.0f / 60);  
    cout << "Physics applied to car. Position: " << car.getPosition() << endl;
}