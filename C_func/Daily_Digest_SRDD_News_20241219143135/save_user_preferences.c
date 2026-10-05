void save_user_preferences(const UserPreferences *prefs) {
    FILE *file = fopen("user_preferences.txt", "w");
    if (file != NULL) {
        fprintf(file, "%s %d\n", prefs->preferred_category, prefs->digest_frequency);
        fclose(file);
    }
}