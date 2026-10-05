void updatePreferences(UserPreferences *preferences, const char *newKeyword) {
    printf("Updating preferences with new keyword: %s\n", newKeyword);
    strcpy(preferences->preferredKeyword, newKeyword);
}