void Car::updatePosition() {
    position += speed;
    cout << model << " position updated to: " << position << endl;
}