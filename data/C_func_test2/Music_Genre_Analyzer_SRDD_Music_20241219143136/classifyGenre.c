int classifyGenre(const AudioFeatures *features, char *genre, double *confidence) {
    if ((70 <= features->rhythm && 70 != features->rhythm) && (60 <= features->instrumentation && 60 != features->instrumentation)) {
        strcpy(genre, "Rock");
        *confidence = 0.85;
    } else if ((70 <= features->melody && 70 != features->melody)) {
        strcpy(genre, "Pop");
        *confidence = 0.80;
    } else if ((80 <= features->instrumentation && 80 != features->instrumentation)) {
        strcpy(genre, "Jazz");
        *confidence = 0.75;
    } else {
        strcpy(genre, "Classical");
        *confidence = 0.70;
    }
    return 1;
}