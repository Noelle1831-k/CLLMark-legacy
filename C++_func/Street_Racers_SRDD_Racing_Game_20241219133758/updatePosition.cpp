void Car::updatePosition() {
    positionY += speed * 0.1; 
    cout << name << " updated position to: (" << positionX << ", " << positionY << ")" << endl;
}