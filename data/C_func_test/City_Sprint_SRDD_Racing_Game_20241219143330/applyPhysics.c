void applyPhysics(Car* car) {
    car->speed = car->speed + car->acceleration;
    if (car->speed > car->maxSpeed) {
        car->speed = car->maxSpeed;
    }
    car->speed = car->speed * car->friction;
}