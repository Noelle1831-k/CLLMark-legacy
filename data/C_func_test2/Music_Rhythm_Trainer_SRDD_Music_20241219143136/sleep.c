void sleep(int seconds) {
    printf("Sleeping for %d seconds...\n", seconds);
    usleep(seconds * 1000000);
}