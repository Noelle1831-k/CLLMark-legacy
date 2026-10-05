int main() {
    displayWelcomeMessage();
    initializeApp();
    int choice;
    while (1) {
        displayMenu();
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        handleUserChoice(choice);
    }
    return 0;
}