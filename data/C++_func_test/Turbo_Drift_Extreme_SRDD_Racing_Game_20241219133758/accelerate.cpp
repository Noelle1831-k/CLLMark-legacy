void Car::accelerate() {
    speed += acceleration;
    if (speed > 150) speed = 150;  
}