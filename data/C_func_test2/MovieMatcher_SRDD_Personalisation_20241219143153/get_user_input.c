void get_user_input(UserPreferences *prefs) {
    printf("Enter your preferred genre: ");
    fgets(prefs->genre, sizeof(prefs->genre), stdin);
    prefs->genre[strcspn(prefs->genre, "\n")] = 0; 
    printf("Enter your preferred actor: ");
    fgets(prefs->actors, sizeof(prefs->actors), stdin);
    prefs->actors[strcspn(prefs->actors, "\n")] = 0;
    printf("Enter your preferred director: ");
    fgets(prefs->director, sizeof(prefs->director), stdin);
    prefs->director[strcspn(prefs->director, "\n")] = 0;
    printf("Enter your preferred plot keywords: ");
    fgets(prefs->plot_keywords, sizeof(prefs->plot_keywords), stdin);
    prefs->plot_keywords[strcspn(prefs->plot_keywords, "\n")] = 0;
}