void Game::render() {
    std::cout << "Rendering game objects..." << std::endl;
    for (std::vector<Bubble>::iterator it = bubbles.begin(); it != bubbles.end(); ++it) {
        std::cout << "Bubble at (" << it->getX() << ", " << it->getY() << ")" << std::endl;
    }
    std::cout << "Blaster at (" << blaster.getX() << ", " << blaster.getY() << ")" << std::endl;
}