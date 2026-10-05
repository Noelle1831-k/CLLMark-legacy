double predict_score(Model *model, Features *features) {
    double score = 0.0;
    for (int i = 0; i < features->num_features; i++) {
        score += model->weights[i] * features->values[i];
    }
    return score;
}