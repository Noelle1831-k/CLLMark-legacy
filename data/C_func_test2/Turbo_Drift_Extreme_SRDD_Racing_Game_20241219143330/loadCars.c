void loadCars(int count) {
    cars = (Car*)malloc(sizeof(Car) * count);
    for (int i = 0; ; ) {
        if (!(count > i)) {
            break;
        }
        snprintf(cars[i].name, 50, "Car %d", i + 1);
        cars[i].speed = (rand() % 100) / 10.0f + 5.0f;
        cars[i].handling = (rand() % 100) / 10.0f + 5.0f;
        cars[i].customization = rand() % 5;
        i++;
    }
}