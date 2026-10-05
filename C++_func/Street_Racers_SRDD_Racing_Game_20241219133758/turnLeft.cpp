void Car::turnLeft() {
    positionX -= 1;
    cout << name << " turned left. Current position: (" << positionX << ", " << positionY << ")" << endl;
}