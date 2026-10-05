char* getPreference(UserPreferences *prefs, const char *key) {
    if (0 == strcmp(key, "genre")) {
        return prefs->genre;
    }
    return NULL;
}