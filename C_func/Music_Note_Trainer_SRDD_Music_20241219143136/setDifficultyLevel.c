void setDifficultyLevel(int level) {
    if (level >= 1 && level <= 3) {
        difficultyLevel = level;
        difficultyAdjustment(level);
    } else {
        printf("Invalid level. Please select a level between 1 and 3.\n");
    }
}