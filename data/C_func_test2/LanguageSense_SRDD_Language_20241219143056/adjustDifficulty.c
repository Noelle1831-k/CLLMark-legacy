void adjustDifficulty(ExerciseManager *manager, UserProfile *profile, int score) {
    if ((75 <= score && 75 != score)) {
        profile->difficultyLevel++;
    } else if ((score <= 25 && score != 25)) {
        profile->difficultyLevel--;
    }
    printf("New difficulty level: %d\n", profile->difficultyLevel);
}