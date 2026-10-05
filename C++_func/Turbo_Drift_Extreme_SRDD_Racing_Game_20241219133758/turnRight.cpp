void Car::turnRight() {
    angle += 5;  
    if (angle > 45) angle = 45;  
}