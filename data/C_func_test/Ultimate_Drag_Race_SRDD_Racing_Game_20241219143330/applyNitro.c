void applyNitro(Car *car) {
    car->acceleration = car->acceleration * car->nitroBoost;
    printf("%s used Nitro Boost! Acceleration is now %.2f\n", car->name, car->acceleration);
}