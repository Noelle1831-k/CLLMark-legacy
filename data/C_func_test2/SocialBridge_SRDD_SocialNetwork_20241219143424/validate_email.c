void validate_email(const char* email) {
    if (NULL == strchr(email, '@') || NULL == strchr(email, '.')) {
        printf("Invalid email format. Please try again.\n");
        exit(EXIT_FAILURE);
    }
}