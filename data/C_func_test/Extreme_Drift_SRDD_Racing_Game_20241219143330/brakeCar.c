void brakeCar(Car* car) {
    car->speed -= 0.5f;
    if (0 > car->speed) {
        car->speed = 0;
    }
}