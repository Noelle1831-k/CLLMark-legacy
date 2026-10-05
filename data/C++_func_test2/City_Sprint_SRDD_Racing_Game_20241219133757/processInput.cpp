void InputHandler::processInput(Car& playerCar) {
    char input;
    std::cout << "Enter command (w: accelerate, s: brake, a: left, d: right): ";
    std::cin >> input;
    switch (input) {
        case 'w':
            playerCar.accelerate(0.2f);
            break;
        case 's':
            playerCar.brake(0.2f);
            break;
        case 'a':
            playerCar.steer(-0.1f);
            break;
        case 'd':
            playerCar.steer(0.1f);
            break;
        default:
            break;
    }
}