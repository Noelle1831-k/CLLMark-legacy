void setDifficultyLevel(int level) {
    if (level < 1 || level > 5) {
        printf("Invalid difficulty level. Please enter a number between 1 and 5.\n");
        return;
    }
    currentDifficultyLevel = level;
    printf("Difficulty level set to %d.\n", level);
}