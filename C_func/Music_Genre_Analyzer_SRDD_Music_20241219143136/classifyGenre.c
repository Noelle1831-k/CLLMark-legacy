int classifyGenre(const AudioFeatures *features, char *genre, double *confidence) {
    if (features->rhythm > 70 && features->instrumentation > 60) {
        strcpy(genre, "Rock");
        *confidence = 0.85;
    } else if (features->melody > 70) {
        strcpy(genre, "Pop");
        *confidence = 0.80;
    } else if (features->instrumentation > 80) {
        strcpy(genre, "Jazz");
        *confidence = 0.75;
    } else {
        strcpy(genre, "Classical");
        *confidence = 0.70;
    }
    return 1;
}