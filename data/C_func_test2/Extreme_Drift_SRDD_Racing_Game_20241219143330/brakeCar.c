void brakeCar(Car* car) {
    car->speed = car->speed - 0.5f;
    if (car->speed < 0) {
        car->speed = 0;
    }
}