void generate_charts() {
    if (chord_count == 0) {
        printf("No chords to visualize.\n");
        return;
    }
    printf("\n=== Chord Relationship Chart ===\n");
    for (int i = 0; i < chord_count - 1; i++) {
        printf("%s -> %s\n", chords[i], chords[i + 1]);
    }
    printf("\n=== Basic Progression Analysis ===\n");
    for (int i = 0; i < chord_count; i++) {
        if (i == chord_count - 1) {
            printf("End of progression: %s\n", chords[i]);
        } else {
            printf("Transition: %s -> %s\n", chords[i], chords[i + 1]);
        }
    }
}