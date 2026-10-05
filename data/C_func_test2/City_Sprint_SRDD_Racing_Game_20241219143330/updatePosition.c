void updatePosition(Car* car) {
    car->position.x += car->speed * cos(car->direction);
    car->position.y += car->speed * sin(car->direction);
    printf("Car position updated to (%.2f, %.2f).\n", car->position.x, car->position.y);
}