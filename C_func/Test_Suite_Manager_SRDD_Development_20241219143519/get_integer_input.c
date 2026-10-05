int get_integer_input() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n'); 
    }
    while (getchar() != '\n'); 
    return value;
}