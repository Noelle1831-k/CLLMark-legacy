void Car::updatePosition(float deltaTime) {
    position += speed * deltaTime * handling;
}