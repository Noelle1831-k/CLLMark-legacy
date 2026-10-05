void Car::turnLeft() {
    angle -= 5;  
    if (angle < -45) angle = -45;  
}