int getUserChoice() {
    char input[10];
    int choice;
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) == 1) {
            return choice;
        } else {
            printf("Invalid input. Please enter a number.\n");
        }
    }
}