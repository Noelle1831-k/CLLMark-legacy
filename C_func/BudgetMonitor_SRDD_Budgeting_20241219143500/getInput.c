int getInput() {
    int input;
    if (scanf("%d", &input) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); 
        return -1;
    }
    return input;
}