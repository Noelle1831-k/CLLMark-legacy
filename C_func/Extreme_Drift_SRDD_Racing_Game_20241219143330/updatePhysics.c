void updatePhysics(Car* car, Track* track) {
    car->speed -= 0.01f;  
    if (car->speed < 0) {
        car->speed = 0;
    }
    car->driftFactor = 1.0f + (car->speed * 0.05f);  
}