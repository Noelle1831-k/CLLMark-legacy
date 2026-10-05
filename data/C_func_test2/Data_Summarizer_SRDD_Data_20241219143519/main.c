int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        if (choice == 0) {
            printf("Exiting application. Goodbye!\n");
            break;
        }
        executeOption(choice);
    }
    return 0;
}