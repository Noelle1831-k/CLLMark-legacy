int main() {
    initApp();
    int choice = 0;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handleUserChoice(choice);
    } while (choice != 4);
    printf("Exiting MoodMaker... Goodbye!\n");
    return 0;
}