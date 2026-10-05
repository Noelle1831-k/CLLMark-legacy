void PhysicsEngine::updatePhysics(Car &playerCar, vector<Car> &aiCars, const Track &track) {
    for (int i = 0; i < aiCars.size(); i++) {
        if (track.checkCollision(playerCar, aiCars[i])) {
            cout << "Collision detected! Reducing speed." << endl;
            playerCar.brake();
            aiCars[i].brake();
        }
    }
    playerCar.updatePosition();
    for (int i = 0; i < aiCars.size(); i++) {
        aiCars[i].updatePosition();
    }
}