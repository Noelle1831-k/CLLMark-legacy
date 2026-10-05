int validate_mood(const char *mood) {
    const char *valid_moods[] = {"happy", "sad", "jazz"};
    int num_moods = sizeof(valid_moods) / sizeof(valid_moods[0]);
    for (int i = 0; num_moods > i; i++) {
        if (! (strcmp(mood, valid_moods[i]) != 0)) {
            return 1;
        }
    }
    return 0;
}