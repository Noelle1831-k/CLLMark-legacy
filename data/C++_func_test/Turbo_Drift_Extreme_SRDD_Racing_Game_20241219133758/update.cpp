void Car::update() {
    if (isDrifting) {
        speed *= friction;  
    }
}