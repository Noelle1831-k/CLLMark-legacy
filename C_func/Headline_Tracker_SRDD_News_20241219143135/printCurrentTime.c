void printCurrentTime() {
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current time: %s", asctime(timeinfo));
}