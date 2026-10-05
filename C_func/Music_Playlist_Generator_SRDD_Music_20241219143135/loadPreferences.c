void loadPreferences(UserPreferences *prefs) {
    printf("Loading user preferences...\n");
    strcpy(prefs->genre, "Rock");
    prefs->tempo = 120;
    printf("Preferences loaded: Genre - %s, Tempo - %d\n", prefs->genre, prefs->tempo);
}