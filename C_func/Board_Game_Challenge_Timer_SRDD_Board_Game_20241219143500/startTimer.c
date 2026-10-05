void startTimer(int seconds) {
    if (seconds <= 0) {
        printf("Error: Invalid timer value.\n");
        return;
    }
    while (seconds > 0) {
        printf("\rTime remaining: %02d:%02d", seconds / 60, seconds % 60);
        fflush(stdout);
        sleep(1);
        seconds--;
    }
    printf("\rTime's up!                \n");
}