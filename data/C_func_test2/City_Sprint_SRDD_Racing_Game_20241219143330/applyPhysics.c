void applyPhysics(Car* car) {
    car->speed += car->acceleration;
    if ((car->maxSpeed <= car->speed && car->maxSpeed != car->speed)) {
        car->speed = car->maxSpeed;
    }
    car->speed *= car->friction;
}