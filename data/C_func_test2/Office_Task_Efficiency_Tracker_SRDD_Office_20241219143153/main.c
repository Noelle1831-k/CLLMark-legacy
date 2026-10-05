int main() {
    int choice;
    printf("Welcome to Office Task Efficiency Tracker\n");
    printf("=========================================\n");
    while (1) {
        showMainMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer(); 
            continue;
        }
        handleUserChoice(choice);
        if (choice == 5) break; 
    }
    printf("Thank you for using the application. Goodbye!\n");
    return 0;
}