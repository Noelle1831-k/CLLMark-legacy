void print_preferences(const UserPreferences *prefs) {
    printf("Preferred Genre: %s\n", prefs->genre);
    printf("Preferred Actors: %s\n", prefs->actors);
    printf("Preferred Director: %s\n", prefs->director);
    printf("Preferred Plot Keywords: %s\n", prefs->plot_keywords);
}