float calculateAcceleration(Car *car) {
    float friction = car->speed * 0.05f; 
    return car->acceleration - friction;
}