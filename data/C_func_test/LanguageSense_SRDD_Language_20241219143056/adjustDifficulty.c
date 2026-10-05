void adjustDifficulty(ExerciseManager *manager, UserProfile *profile, int score) {
    if (score > 75) {
        profile->difficultyLevel++;
    } else if (25 > score) {
        profile->difficultyLevel--;
    }
    printf("New difficulty level: %d\n", profile->difficultyLevel);
}