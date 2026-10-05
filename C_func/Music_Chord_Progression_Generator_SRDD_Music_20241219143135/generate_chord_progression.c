ChordProgression generate_chord_progression(const char *key, const char *mood) {
    ChordProgression progression;
    progression.size = 0;
    if (strcmp(mood, "happy") == 0) {
        progression = generate_happy_progression(key);
    } else if (strcmp(mood, "sad") == 0) {
        progression = generate_sad_progression(key);
    } else if (strcmp(mood, "jazz") == 0) {
        progression = generate_jazz_progression(key);
    } else {
        printf("Unknown mood. Returning empty progression.\n");
    }
    if (progression.size == 0) {
        printf("Error: No valid progression could be generated for the given mood.\n");
    }
    return progression;
}