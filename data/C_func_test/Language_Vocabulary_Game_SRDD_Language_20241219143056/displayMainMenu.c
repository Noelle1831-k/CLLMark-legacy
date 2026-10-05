int displayMainMenu() {
    printf("\n--- Language Vocabulary Game ---\n");
    printf("1. Start Game\n");
    printf("2. View Progress Dashboard\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}