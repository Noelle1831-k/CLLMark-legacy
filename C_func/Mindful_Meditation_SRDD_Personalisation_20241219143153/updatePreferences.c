void updatePreferences(const char* style, int duration, const char* theme) {
    printf("Updating user preferences...\n");
    strcpy(preferences.meditationStyle, style);
    preferences.sessionDuration = duration;
    strcpy(preferences.theme, theme);
    savePreferences();
}