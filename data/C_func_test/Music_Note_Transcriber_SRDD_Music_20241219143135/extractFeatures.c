double *extractFeatures(double *audioData) {
    double *features = (double *)malloc(100 * sizeof(double));
    if (!features) {
        fprintf(stderr, "Memory allocation failed for features.\n");
        exit(1);
    }
    for (int i = 0; i < 100; i++) {
        features[i] = audioData[i] * 0.5;
    }
    return features;
}