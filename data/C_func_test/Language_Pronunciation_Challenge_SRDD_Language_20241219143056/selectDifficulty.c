void selectDifficulty() {
    int difficulty;
    printf("Select difficulty level (1: Easy, 2: Medium, 3: Hard):\n");
    scanf("%d", &difficulty);
    switch (difficulty) {
        case 1:
            printf("Easy difficulty selected.\n");
            break;
        case 2:
            printf("Medium difficulty selected.\n");
            break;
        case 3:
            printf("Hard difficulty selected.\n");
            break;
        default:
            printf("Invalid selection. Defaulting to Easy.\n");
            break;
    }
}