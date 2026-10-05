void createChordHandler() {
    char name[50];
    int duration;
    printf("Enter chord name (e.g., C, G, Am): ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; 
    printf("Enter chord duration in beats: ");
    scanf("%d", &duration);
    getchar(); 
    Chord* chord = createChord(name, duration);
    printf("Created chord: %s with duration: %d beats\n", chord->name, chord->duration);
}