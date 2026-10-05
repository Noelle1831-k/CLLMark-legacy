void validate_email(const char* email) {
    if (strchr(email, '@') == NULL || strchr(email, '.') == NULL) {
        printf("Invalid email format. Please try again.\n");
        exit(EXIT_FAILURE);
    }
}