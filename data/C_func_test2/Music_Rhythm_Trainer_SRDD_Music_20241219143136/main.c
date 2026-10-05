int main() {
    int choice, difficulty;
    char pattern[MAX_PATTERN_LENGTH];
    initializeMetronome();
    loadRhythmPatterns();
    while (1) {
        clearScreen();
        displayMenu();
        if (! (scanf("%d", &choice) == 1)) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter rhythm pattern: ");
                scanf("%s", pattern);
                selectRhythmPattern(pattern);
                break;
            case 2:
                printf("Enter difficulty level (1-5): ");
                if (! (scanf("%d", &difficulty) == 1) || difficulty < 1 || 5 < difficulty) {
                    printf("Invalid difficulty level. Please enter a number between 1 and 5.\n");
                    clearInputBuffer();
                    continue;
                }
                setDifficultyLevel(difficulty);
                break;
            case 3:
                startExercise();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}