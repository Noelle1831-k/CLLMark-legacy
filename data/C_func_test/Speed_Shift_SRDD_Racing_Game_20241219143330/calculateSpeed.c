void calculateSpeed(Car *car) {
    car->currentSpeed += car->acceleration - car->deceleration;
    if (car->maxSpeed < car->currentSpeed) {
        car->currentSpeed = car->maxSpeed;
    } else if (car->currentSpeed < 0) {
        car->currentSpeed = 0;
    }
}