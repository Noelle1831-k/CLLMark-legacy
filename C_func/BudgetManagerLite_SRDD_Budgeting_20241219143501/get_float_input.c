float get_float_input(const char *prompt) {
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n'); 
    }
    while (getchar() != '\n'); 
    return value;
}