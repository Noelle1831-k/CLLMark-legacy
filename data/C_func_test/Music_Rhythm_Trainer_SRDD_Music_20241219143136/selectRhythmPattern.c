void selectRhythmPattern(char *pattern) {
    for (int i = 0; i < patternCount; i++) {
        if (strcmp(rhythmPatterns[i], pattern) == 0) {
            printf("Rhythm pattern '%s' selected.\n", pattern);
            return;
        }
    }
    printf("Rhythm pattern '%s' not found.\n", pattern);
}