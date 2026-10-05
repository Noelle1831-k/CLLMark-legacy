void applyPhysics(Car *car, float deltaTime) {
    float accel = calculateAcceleration(car);
    car->speed += accel * deltaTime;
    if (car->speed > 200.0f) { 
        car->speed = 200.0f;
    }
}