Features* extract_features(GameData *data) {
    Features *features = (Features *)malloc(sizeof(Features));
    if (!features) {
        perror("Failed to allocate memory for features");
        return NULL;
    }
    features->num_features = 10; 
    features->values = (double *)malloc(features->num_features * sizeof(double));
    if (!features->values) {
        perror("Failed to allocate memory for feature values");
        free(features);
        return NULL;
    }
    for (int i = 0; i < features->num_features; i++) {
        features->values[i] = (double)(rand() % 100) / 100.0; 
    }
    return features;
}