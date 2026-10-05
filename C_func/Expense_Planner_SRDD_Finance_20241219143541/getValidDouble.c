bool getValidDouble(const char* prompt, double* value) {
    printf("%s", prompt);
    while (scanf("%lf", value) != 1 || *value < 0) {
        printf("Invalid input. Please enter a non-negative number: ");
        clearInputBuffer();
    }
    return true;
}