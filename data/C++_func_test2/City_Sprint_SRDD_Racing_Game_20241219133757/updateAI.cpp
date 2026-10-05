void AIController::updateAI(std::vector<Car>& aiCars, const Track& track) {
    for (auto& aiCar : aiCars) {
        aiCar.accelerate(0.1f);
        if (track.checkCollision(aiCar.getPositionX(), aiCar.getPositionY())) {
            aiCar.steer(0.1f);
        }
    }
}