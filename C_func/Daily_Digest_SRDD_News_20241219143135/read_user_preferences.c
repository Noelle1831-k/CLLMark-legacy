void read_user_preferences(UserPreferences *prefs) {
    FILE *file = fopen("user_preferences.txt", "r");
    if (file == NULL) {
        set_default_preferences(prefs);
        return;
    }
    fscanf(file, "%s %d", prefs->preferred_category, &prefs->digest_frequency);
    fclose(file);
}