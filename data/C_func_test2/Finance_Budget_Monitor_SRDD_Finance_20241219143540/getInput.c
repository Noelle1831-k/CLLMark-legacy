int getInput() {
    int input;
    while (1 != scanf("%d", &input)) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n'); 
    }
    return input;
}