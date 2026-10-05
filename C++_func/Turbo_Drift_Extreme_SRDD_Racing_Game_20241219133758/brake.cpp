void Car::brake() {
    speed -= acceleration;
    if (speed < 0) speed = 0;  
}