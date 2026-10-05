int getUserInput() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); 
        return -1;
    }
    return choice;
}