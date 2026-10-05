void logMessage(const char *message) {
    time_t now;
    time(&now);
    printf("Log [%s]: %s\n", ctime(&now), message);
}