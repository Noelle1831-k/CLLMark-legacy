int getUserChoice() {
    char input[10];
    int choice;
    printf("Enter your choice: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        if (sscanf(input, "%d", &choice) == 1) {
            return choice;
        }
    }
    printf("Invalid input. Please enter a number.\n");
    return -1; 
}