void handleInput() {
    char input;
    printf("Enter control (w: accelerate, s: brake, a: steer left, d: steer right, q: quit): ");
    scanf(" %c", &input);
    if (input == 'w') {
        accelerateCar(&playerCar);
    } else if (input == 's') {
        brakeCar(&playerCar);
    } else if (input == 'a') {
        steerLeft(&playerCar);
    } else if (input == 'd') {
        steerRight(&playerCar);
    } else if (input == 'q') {
        gameRunning = false;
    }
}