void Car::brake() {
    speed = speed - acceleration;
    if (speed < 0) speed = 0;  
}