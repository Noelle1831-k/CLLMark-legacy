void Car::updatePosition() {
    position += speed * cos(direction);
}