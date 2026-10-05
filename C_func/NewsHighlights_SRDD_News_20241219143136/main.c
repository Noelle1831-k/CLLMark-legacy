int main() {
    int choice;
    printf("Welcome to NewsHighlights!\n");
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handleUserChoice(choice);
        if (choice == 5) {
            printf("Exiting NewsHighlights. Goodbye!\n");
            break;
        }
    }
    return 0;
}