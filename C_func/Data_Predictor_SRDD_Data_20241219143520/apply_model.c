double apply_model(double *input) {
    double prediction = 0.0;
    for (int i = 0; i < cols - 1; i++) {
        prediction += theta[i] * input[i];
    }
    return prediction;
}