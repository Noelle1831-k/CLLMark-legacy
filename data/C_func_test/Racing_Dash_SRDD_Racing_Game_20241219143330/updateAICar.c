void updateAICar(Car* car) {
    car->speed += car->acceleration;  
    if (car->speed > car->maxSpeed) {
        car->speed = car->maxSpeed;  
    }
    car->x += car->speed;
}