void interactWithContent() {
    int action;
    printf("\n--- Interact with Content ---\n");
    printf("Choose an action:\n");
    printf("1. Like\n");
    printf("2. Comment\n");
    printf("3. Save\n");
    printf("Enter your choice: ");
    scanf("%d", &action);
    switch (action) {
        case 1: likeContent(); break;
        case 2: commentContent(); break;
        case 3: saveContent(); break;
        default: printf("Invalid action. Returning to main menu.\n");
    }
}