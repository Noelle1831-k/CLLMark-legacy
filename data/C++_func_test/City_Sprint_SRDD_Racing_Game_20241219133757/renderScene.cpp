void GraphicsEngine::renderScene(const Car& playerCar, const std::vector<Car>& aiCars, const Track& track) {
    std::cout << "Rendering scene..." << std::endl;
    std::cout << "Player Car - Position: (" << playerCar.getPositionX() << ", " << playerCar.getPositionY() << ") Speed: " << playerCar.getSpeed() << std::endl;
    for (const auto& aiCar : aiCars) {
        std::cout << "AI Car - Position: (" << aiCar.getPositionX() << ", " << aiCar.getPositionY() << ") Speed: " << aiCar.getSpeed() << std::endl;
    }
}