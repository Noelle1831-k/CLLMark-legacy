void freeUserPreferences(UserPreferences *preferences) {
    if (preferences != NULL) {
        free(preferences->usageTimes);
        for (int i = 0; i < preferences->count; i++) {
            free(preferences->features[i]);
        }
        free(preferences->features);
        free(preferences);
    }
}