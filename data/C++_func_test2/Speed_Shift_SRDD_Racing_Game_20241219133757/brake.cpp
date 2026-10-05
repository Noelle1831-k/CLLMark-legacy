void Car::brake() {
    speed -= 10;
    if (speed < 0) speed = 0;
}