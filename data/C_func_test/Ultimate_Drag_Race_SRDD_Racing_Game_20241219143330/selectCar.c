Car selectCar(int index) {
    if (index < 0 || index >= 5) {
        printf("Invalid car selection. Defaulting to Speedster.\n");
        return cars[0];
    }
    return cars[index];
}