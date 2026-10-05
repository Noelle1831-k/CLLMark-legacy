void printCurrentTime() {
    time_t t;
    time(&t);
    printf("Current Time: %s\n", ctime(&t));
}