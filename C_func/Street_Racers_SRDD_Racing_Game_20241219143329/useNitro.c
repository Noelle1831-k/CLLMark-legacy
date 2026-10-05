void useNitro(Car *car) {
    if (car->nitro > 0) {
        car->speed += 20;
        car->nitro--;
    }
}