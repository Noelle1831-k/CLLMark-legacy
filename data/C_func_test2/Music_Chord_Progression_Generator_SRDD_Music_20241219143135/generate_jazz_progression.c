ChordProgression generate_jazz_progression(const char *key) {
    ChordProgression progression;
    progression.size = 4;
    progression.chords = malloc(sizeof(char *) * progression.size);
    progression.chords[0] = get_chord(key, "ii7");
    progression.chords[1] = get_chord(key, "V7");
    progression.chords[2] = get_chord(key, "Imaj7");
    progression.chords[3] = get_chord(key, "vi7");
    return progression;
}