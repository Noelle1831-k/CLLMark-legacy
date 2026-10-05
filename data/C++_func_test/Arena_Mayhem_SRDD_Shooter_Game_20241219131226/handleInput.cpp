void GameEngine::handleInput() {
    char input;
    std::cout << "Enter command (W/A/S/D for movement, F to fire, P for power-up): ";
    std::cin >> input;
    switch (input) {
        case 'W':
        case 'w':
            player.move(0, -1); 
            break;
        case 'A':
        case 'a':
            player.move(-1, 0); 
            break;
        case 'S':
        case 's':
            player.move(0, 1); 
            break;
        case 'D':
        case 'd':
            player.move(1, 0); 
            break;
        case 'F':
        case 'f':
            if (!weapons.empty()) {
                weapons[0].fire(); 
            } else {
                std::cout << "No weapons available!" << std::endl;
            }
            break;
        case 'P':
        case 'p':
            if (!powerUps.empty()) {
                powerUps[0].activate(); 
            } else {
                std::cout << "No power-ups available!" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid command!" << std::endl;
            break;
    }
}