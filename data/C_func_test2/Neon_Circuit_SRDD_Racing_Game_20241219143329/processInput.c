void processInput() {
    printf("Processing input...\n");
    char input;
    printf("Press 'W' to accelerate, 'S' to decelerate, 'A' to steer left, 'D' to steer right: ");
    scanf(" %c", &input);
    if (input == 'W') {
        printf("Accelerating...\n");
    } else if (input == 'S') {
        printf("Decelerating...\n");
    } else if (input == 'A') {
        printf("Steering left...\n");
    } else if (input == 'D') {
        printf("Steering right...\n");
    }
}