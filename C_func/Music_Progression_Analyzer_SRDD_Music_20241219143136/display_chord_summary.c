void display_chord_summary() {
    printf("\n=== Chord Summary ===\n");
    for (int i = 0; i < chord_count; i++) {
        printf("Chord %d: %s\n", i + 1, chords[i]);
    }
}