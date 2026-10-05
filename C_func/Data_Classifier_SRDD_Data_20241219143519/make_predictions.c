int make_predictions(Model *model, DataSet *data) {
    for (int row = 0; row < data->num_rows; row++) {
        data->predictions[row] = 1;  
    }
    return 0;
}