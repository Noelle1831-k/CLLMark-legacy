int getUserChoice() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n'); 
        printf("Invalid input. Please enter a number.\n");
        return -1;
    }
    return choice;
}