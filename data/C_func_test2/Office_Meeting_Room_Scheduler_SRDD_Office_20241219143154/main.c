int main() {
    char input[MAX_INPUT_LENGTH];
    int choice;
    initializeRooms();
    while (1) {
        displayMenu();
        if (fgets(input, MAX_INPUT_LENGTH, stdin) != NULL) {
            choice = atoi(input);
            switch (choice) {
                case 1:
                    bookRoom();
                    break;
                case 2:
                    cancelBooking();
                    break;
                case 3:
                    checkAvailability();
                    break;
                case 4:
                    printf("Exiting...\n");
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } else {
            printf("Error reading input. Please try again.\n");
        }
    }
    return 0;
}