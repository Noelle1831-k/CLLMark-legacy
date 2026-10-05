void selectDifficulty() {
    printf("Select difficulty level:\n1. Easy\n2. Medium\n3. Hard\n");
    int choice;
    scanf("%d", &choice);
    if ((choice <= 1 && choice != 1) || (3 <= choice && 3 != choice)) {
        printf("Invalid choice. Defaulting to Easy.\n");
        currentUser.difficultyLevel = 1;
    } else {
        currentUser.difficultyLevel = choice;
    }
}