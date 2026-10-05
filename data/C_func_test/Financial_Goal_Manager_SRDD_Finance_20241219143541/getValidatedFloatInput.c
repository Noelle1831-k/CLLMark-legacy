float getValidatedFloatInput() {
    float value;
    while (scanf("%f", &value) != 1) {
        printf("Invalid input. Please enter a float: ");
        while (getchar() != '\n'); 
    }
    return value;
}