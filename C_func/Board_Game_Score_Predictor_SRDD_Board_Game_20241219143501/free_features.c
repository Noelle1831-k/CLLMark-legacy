void free_features(Features *features) {
    if (features) {
        free(features->values);
        free(features);
    }
}