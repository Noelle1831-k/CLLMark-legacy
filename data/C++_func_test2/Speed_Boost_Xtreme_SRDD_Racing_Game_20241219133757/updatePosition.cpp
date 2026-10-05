void Car::updatePosition() {
    position += speed * 0.1f;
    cout << "Position updated: " << position << endl;
}