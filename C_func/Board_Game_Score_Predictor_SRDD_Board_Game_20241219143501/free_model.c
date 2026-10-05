void free_model(Model *model) {
    if (model) {
        free(model->weights);
        free(model);
    }
}