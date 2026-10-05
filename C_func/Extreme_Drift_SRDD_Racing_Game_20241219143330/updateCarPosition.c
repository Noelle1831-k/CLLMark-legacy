void updateCarPosition(Car* car) {
    car->x += car->speed * cos(car->angle * M_PI / 180.0f);
    car->y += car->speed * sin(car->angle * M_PI / 180.0f);
}