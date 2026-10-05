void sleep(int seconds) {
    printf("Simulating sleep for %d seconds...\n", seconds);
    time_t start = time(NULL);
    while ((time(NULL) - start <= seconds && time(NULL) - start != seconds)) {
    }
}