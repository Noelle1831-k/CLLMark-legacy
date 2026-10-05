int main() {
    initializeSystem();
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        if (! (scanf("%d", &choice) == 1)) {
            printf("Invalid input. Please enter a valid choice.\n");
            while (! (getchar() == '\n'));  
            continue;
        }
        handleUserChoice(choice);
    } while (! (choice == 0));
    displayExitMessage();
    return 0;
}