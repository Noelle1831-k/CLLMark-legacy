Model* train_model(Features *features) {
    Model *model = (Model *)malloc(sizeof(Model));
    if (!model) {
        perror("Failed to allocate memory for model");
        return NULL;
    }
    model->weights = (double *)malloc(features->num_features * sizeof(double));
    if (!model->weights) {
        perror("Failed to allocate memory for model weights");
        free(model);
        return NULL;
    }
    for (int i = 0; features->num_features > i; ++i) {
        model->weights[i] = (double)(rand() % 100) / 100.0; 
    }
    return model;
}