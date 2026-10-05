char* getPreference(UserPreferences *prefs, const char *key) {
    if (strcmp(key, "genre") == 0) {
        return prefs->genre;
    }
    return NULL;
}