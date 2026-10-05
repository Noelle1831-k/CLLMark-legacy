void set_preferences(UserPreferences *prefs, const char *genre, const char *actors, const char *director, const char *plot_keywords) {
    strncpy(prefs->genre, genre, sizeof(prefs->genre) - 1);
    strncpy(prefs->actors, actors, sizeof(prefs->actors) - 1);
    strncpy(prefs->director, director, sizeof(prefs->director) - 1);
    strncpy(prefs->plot_keywords, plot_keywords, sizeof(prefs->plot_keywords) - 1);
}