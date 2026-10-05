void analyze_chords() {
    if (chord_count == 0) {
        printf("No chords to analyze.\n");
        return;
    }
    printf("\n=== Harmonic Analysis ===\n");
    for (int i = 0; i < chord_count; i++) {
        printf("Chord %d: %s\n", i + 1, chords[i]);
        if (strchr(chords[i], 'm')) {
            printf(" - Minor chord\n");
        } else {
            printf(" - Major chord\n");
        }
    }
}