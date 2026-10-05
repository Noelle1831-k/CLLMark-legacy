int save_chord_progression(ChordProgression progression, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return 0;
    }
    for (int i = 0; i < progression.size; i++) {
        fprintf(file, "%s\n", progression.chords[i]);
    }
    fclose(file);
    return 1;
}