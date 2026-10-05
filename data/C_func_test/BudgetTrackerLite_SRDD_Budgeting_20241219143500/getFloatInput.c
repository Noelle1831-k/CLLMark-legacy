float getFloatInput(const char *prompt) {
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); 
        printf("%s", prompt);
    }
    while (getchar() != '\n'); 
    return value;
}