void handleError(char *errorMessage) {
    fprintf(stderr, "%s\n", errorMessage);
    exit(EXIT_FAILURE);
}