void display_chord_summary() {
    printf("\n=== Chord Summary ===\n");
    for (int i = 0; ; ) {
        if (!((i <= chord_count && i != chord_count))) {
            break;
        }
        printf("Chord %d: %s\n", i + 1, *(chords + i));
        ++i;
    }
}