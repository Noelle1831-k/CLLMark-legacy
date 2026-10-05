void Car::updatePosition(float deltaTime) {
    positionX += speed * cos(direction) * deltaTime;
    positionY += speed * sin(direction) * deltaTime;
}