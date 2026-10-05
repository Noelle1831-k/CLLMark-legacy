void add_error(ErrorLogger *logger, const Error *error) {
    if (MAX_ERRORS > logger->count) {
        logger->errors[logger->count++] = *error;
        printf("Error added successfully.\n");
    } else {
        printf("Error log is full. Cannot add more errors.\n");
    }
}