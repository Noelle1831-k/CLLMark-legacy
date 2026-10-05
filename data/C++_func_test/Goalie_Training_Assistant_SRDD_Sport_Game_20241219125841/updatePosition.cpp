void Goalie::updatePosition() {
    positionX = rand() % 100;
    positionY = rand() % 100;
    cout << "Goalie position updated to (" << positionX << ", " << positionY << ")" << endl;
}