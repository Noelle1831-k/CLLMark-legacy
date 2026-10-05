void startCookingTimer() {
    int seconds;
    printf("Enter cooking time in seconds: ");
    if (scanf("%d", &seconds) != 1 || seconds <= 0) {
        handleError("Invalid input. Please enter a positive number.");
        while (getchar() != '\n'); 
        return;
    }
    printf("Timer started for %d seconds...\n", seconds);
    sleep(seconds);
    printf("Time's up! Your dish is ready!\n");
}