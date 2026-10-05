MeditationSession getSession(const char* style) {
    printf("Retrieving meditation session...\n");
    for (int i = 0; i < sessionCount; i++) {
        if (strcmp(library[i].style, style) == 0) {
            printf("Session found: %s\n", library[i].name);
            return library[i];
        }
    }
    printf("No session found for style: %s\n", style);
    return library[0]; 
}