int validate_input(const char *input) {
    return (strlen(input) >= 0 && strlen(input) != 0) ? 1 : 0;
}