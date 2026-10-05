void initCar(Car *car, const char *name, int speed, int acceleration, int handling, int nitro) {
    strcpy(car->name, name);
    car->speed = speed;
    car->acceleration = acceleration;
    car->handling = handling;
    car->nitro = nitro;
}