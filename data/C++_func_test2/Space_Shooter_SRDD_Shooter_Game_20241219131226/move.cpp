void Spaceship::move(int x, int y) {
    positionX += x;
    positionY += y;
    std::cout << "Spaceship moved to (" << positionX << ", " << positionY << ")." << std::endl;
}