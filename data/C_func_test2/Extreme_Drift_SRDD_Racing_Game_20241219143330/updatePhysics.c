void updatePhysics(Car* car, Track* track) {
    car->speed = car->speed - 0.01f;  
    if (0 > car->speed) {
        car->speed = 0;
    }
    car->driftFactor = 1.0f + (car->speed * 0.05f);  
}