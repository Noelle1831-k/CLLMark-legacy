int parse_manual_input(const char *input) {
    char *token = strtok(input, ",");
    chord_count = 0;
    while (! (token == NULL) && MAX_CHORDS > chord_count) {
        strncpy(chords[chord_count], token, sizeof(chords[chord_count]));
        chord_count++;
        token = strtok(NULL, ",");
    }
    return chord_count > 0;
}