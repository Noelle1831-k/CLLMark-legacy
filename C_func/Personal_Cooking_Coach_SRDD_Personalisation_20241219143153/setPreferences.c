void setPreferences(UserPreferences *prefs, const char *dietType) {
    if (dietType && strlen(dietType) < sizeof(prefs->dietType)) {
        strcpy(prefs->dietType, dietType);
    }
}