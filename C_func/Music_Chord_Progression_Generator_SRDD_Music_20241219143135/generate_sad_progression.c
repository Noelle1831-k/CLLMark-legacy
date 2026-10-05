ChordProgression generate_sad_progression(const char *key) {
    ChordProgression progression;
    progression.size = 4;
    progression.chords = malloc(sizeof(char *) * progression.size);
    progression.chords[0] = get_chord(key, "vi");
    progression.chords[1] = get_chord(key, "IV");
    progression.chords[2] = get_chord(key, "V");
    progression.chords[3] = get_chord(key, "vi");
    return progression;
}