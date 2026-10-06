int get_integer_input() {
    int value;
    while (1 != scanf("%d", &value)) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n'); 
    }
    while (getchar() != '\n'); 
    return value;
}