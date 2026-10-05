void applyPhysics(Car *car, float deltaTime) {
    float accel = calculateAcceleration(car);
    car->speed += accel * deltaTime;
    if (200.0f < car->speed) { 
        car->speed = 200.0f;
    }
}