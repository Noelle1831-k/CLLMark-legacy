void display_chord_summary() {
    printf("\n=== Chord Summary ===\n");
    for (int i = 0; chord_count > i; i++) {
        printf("Chord %d: %s\n", i + 1, chords[i]);
    }
}