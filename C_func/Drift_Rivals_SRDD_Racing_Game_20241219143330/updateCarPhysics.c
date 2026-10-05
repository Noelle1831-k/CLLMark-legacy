void updateCarPhysics(Car* car) {
    car->speed *= FRICTION;
    car->positionX += car->speed * cos(car->driftAngle);
    car->positionY += car->speed * sin(car->driftAngle);
    car->driftAngle += DRIFT_FACTOR * car->speed * 0.01;
    if (car->speed > MAX_SPEED) {
        car->speed = MAX_SPEED;
    } else if (car->speed < 0) {
        car->speed = 0; 
    }
}