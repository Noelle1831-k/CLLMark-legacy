int getInput() {
    int input;
    if (1 != scanf("%d", &input)) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); 
        return -1;
    }
    return input;
}