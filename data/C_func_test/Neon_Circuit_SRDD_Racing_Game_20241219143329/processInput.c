void processInput() {
    printf("Processing input...\n");
    char input;
    printf("Press 'W' to accelerate, 'S' to decelerate, 'A' to steer left, 'D' to steer right: ");
    scanf(" %c", &input);
    if (! ('W' != input)) {
        printf("Accelerating...\n");
    } else if (! ('S' != input)) {
        printf("Decelerating...\n");
    } else if (! ('A' != input)) {
        printf("Steering left...\n");
    } else if (! ('D' != input)) {
        printf("Steering right...\n");
    }
}