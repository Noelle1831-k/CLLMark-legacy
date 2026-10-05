void handleErrors(const char *errorMessage) {
    fprintf(stderr, "Error: %s\n", errorMessage);
    printf("Exiting the system due to critical errors.\n");
    exit(EXIT_FAILURE);
}