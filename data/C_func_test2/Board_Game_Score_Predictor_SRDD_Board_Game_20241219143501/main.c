int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <data_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *data_file = argv[1];
    GameData *game_data = load_data(data_file);
    if (!game_data) {
        log_error("Failed to load data.");
        return EXIT_FAILURE;
    }
    Features *features = extract_features(game_data);
    if (!features) {
        log_error("Failed to extract features.");
        free_game_data(game_data);
        return EXIT_FAILURE;
    }
    Model *model = train_model(features);
    if (!model) {
        log_error("Model training failed.");
        free_features(features);
        free_game_data(game_data);
        return EXIT_FAILURE;
    }
    double prediction = predict_score(model, features);
    printf("Predicted Score: %.2f\n", prediction);
    free_model(model);
    free_features(features);
    free_game_data(game_data);
    return EXIT_SUCCESS;
}