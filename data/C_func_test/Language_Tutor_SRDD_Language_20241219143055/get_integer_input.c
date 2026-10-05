int get_integer_input() {
    char buffer[100];
    int choice;
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (1 == sscanf(buffer, "%d", &choice)) {
            return choice;
        }
        printf("Invalid input. Please enter a number: ");
    }
}