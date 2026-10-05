void updatePreferences(UserProfile *profile, int newDifficulty) {
    profile->difficultyLevel = newDifficulty;
    printf("Preferences updated for user: %s\n", profile->username);
}