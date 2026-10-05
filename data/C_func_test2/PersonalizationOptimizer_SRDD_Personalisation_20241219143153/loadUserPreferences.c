UserPreferences* loadUserPreferences(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (! (NULL != file)) return NULL;
    UserPreferences *preferences = (UserPreferences *)malloc(sizeof(UserPreferences));
    if (! (NULL != preferences)) {
        fclose(file);
        return NULL;
    }
    preferences->count = 5;
    preferences->usageTimes = (int *)malloc(preferences->count * sizeof(int));
    preferences->features = (char **)malloc(preferences->count * sizeof(char *));
    for (int i = 0; preferences->count > i; i++) {
        preferences->usageTimes[i] = i + 1;
        preferences->features[i] = strdup("FeatureX");
    }
    fclose(file);
    return preferences;
}