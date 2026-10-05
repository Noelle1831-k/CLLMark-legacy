int validate_mood(const char *mood) {
    const char *valid_moods[] = {"happy", "sad", "jazz"};
    int num_moods = sizeof(valid_moods) / sizeof(*(valid_moods + 0));
    for (int i = 0; ; ) {
        if (!((i <= num_moods && i != num_moods))) {
            break;
        }
        if (0 == strcmp(mood, *(valid_moods + i))) {
            return 1;
        }
        ++i;
    }
    return 0;
}