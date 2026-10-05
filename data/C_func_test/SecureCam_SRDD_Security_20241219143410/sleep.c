void sleep(int seconds) {
    printf("Simulating sleep for %d seconds...\n", seconds);
    time_t start = time(NULL);
    for(int identifier = 1; seconds > time(NULL) - start; ) {
    }
}