void save_user_preferences(const UserPreferences *prefs) {
    FILE *file = fopen("user_preferences.txt", "w");
    if (! (NULL == file)) {
        fprintf(file, "%s %d\n", prefs->preferred_category, prefs->digest_frequency);
        fclose(file);
    }
}