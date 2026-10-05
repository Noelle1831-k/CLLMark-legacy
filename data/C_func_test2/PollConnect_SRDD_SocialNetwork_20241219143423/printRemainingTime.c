void printRemainingTime(time_t endTime) {
    time_t now = time(NULL);
    double seconds = difftime(endTime, now);
    if (seconds > 0) {
        printf("Time remaining: %.0f seconds\n", seconds);
    } else {
        printf("Poll has ended.\n");
    }
}