UserPreferences* create_user_preferences() {
    UserPreferences *prefs = (UserPreferences*)malloc(sizeof(UserPreferences));
    if (prefs == NULL) {
        fprintf(stderr, "Memory allocation failed for user preferences\n");
        exit(EXIT_FAILURE);
    }
    return prefs;
}