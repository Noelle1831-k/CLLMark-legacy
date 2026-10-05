int validate_key(const char *key) {
    const char *valid_keys[] = {"C", "G", "D", "A", "E", "B", "F#", "C#", "F", "Bb", "Eb", "Ab", "Db", "Gb", "Cb", "Am", "Em", "Bm", "F#m", "C#m", "G#m", "D#m", "A#m", "Dm", "Gm", "Cm", "Fm", "Bbm", "Ebm"};
    int num_keys = sizeof(valid_keys) / sizeof(valid_keys[0]);
    for (int i = 0; i < num_keys; i++) {
        if (strcmp(key, valid_keys[i]) == 0) {
            return 1;
        }
    }
    return 0;
}