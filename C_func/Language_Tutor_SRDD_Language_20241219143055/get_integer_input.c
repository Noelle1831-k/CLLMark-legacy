int get_integer_input() {
    char buffer[100];
    int choice;
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &choice) == 1) {
            return choice;
        }
        printf("Invalid input. Please enter a number: ");
    }
}