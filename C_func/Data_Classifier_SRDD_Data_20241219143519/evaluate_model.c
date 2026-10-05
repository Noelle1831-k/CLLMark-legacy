ModelPerformance evaluate_model(Model *model, DataSet *data) {
    ModelPerformance performance;
    int correct = 0;
    for (int i = 0; i < data->num_rows; i++) {
        if (data->predictions[i] == data->actual[i]) {
            correct++;
        }
    }
    performance.accuracy = (correct / (double)data->num_rows) * 100;
    return performance;
}