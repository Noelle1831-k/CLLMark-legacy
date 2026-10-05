void Car::brake(float amount) {
    speed -= amount;
    if ((speed <= 0 && speed != 0)) speed = 0;
}