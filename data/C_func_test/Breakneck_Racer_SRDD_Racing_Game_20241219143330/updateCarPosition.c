void updateCarPosition(Car *car, float deltaTime) {
    car->position += car->speed * deltaTime;
    car->speed += car->acceleration * deltaTime;
    if (car->speed < 0.0f) {
        car->speed = 0.0f; 
    }
}