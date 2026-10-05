char* determine_emotional_tone(const char *lyrics) {
    char *emotional_tone = (char *)malloc(50 * sizeof(char));
    if (emotional_tone == NULL) {
        fprintf(stderr, "Memory allocation failed for emotional_tone\n");
        exit(EXIT_FAILURE);
    }
    strcpy(emotional_tone, "Happy");
    return emotional_tone;
}