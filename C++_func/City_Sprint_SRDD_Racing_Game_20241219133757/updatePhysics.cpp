void PhysicsEngine::updatePhysics(Car& playerCar, std::vector<Car>& aiCars, const Track& track) {
    playerCar.accelerate(0.1f);
    if (track.checkCollision(playerCar.getPositionX(), playerCar.getPositionY())) {
        playerCar.brake(0.5f);
    }
    for (auto& aiCar : aiCars) {
        aiCar.accelerate(0.05f);
        if (track.checkCollision(aiCar.getPositionX(), aiCar.getPositionY())) {
            aiCar.brake(0.3f);
        }
    }
}