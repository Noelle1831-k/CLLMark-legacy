int main() {
    char input_file[] = "data.csv";  
    char output_file[] = "results.csv";  
    DataSet data;
    Model model;
    if (load_data(input_file, &data) != 0) {
        printf("Error: Failed to load data from %s\n", input_file);
        return 1;
    }
    if (preprocess_data(&data) != 0) {
        printf("Error: Data preprocessing failed\n");
        return 1;
    }
    if (train_model(&data, &model) != 0) {
        printf("Error: Model training failed\n");
        return 1;
    }
    ModelPerformance performance = evaluate_model(&model, &data);
    printf("Model Accuracy: %.2f%%\n", performance.accuracy);
    if (make_predictions(&model, &data) != 0) {
        printf("Error: Prediction generation failed\n");
        return 1;
    }
    if (export_results(output_file, &data) != 0) {
        printf("Error: Failed to export results to %s\n", output_file);
        return 1;
    }
    printf("Data classification completed successfully. Results saved to %s\n", output_file);
    return 0;
}