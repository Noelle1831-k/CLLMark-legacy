Anomalies* detectAnomalies(Dataset *dataset) {
    Anomalies *anomalies = (Anomalies *)malloc(sizeof(Anomalies));
    anomalies->count = 0;
    for (int col = 0; col < dataset->columnCount; col++) {
        double mean = 0.0, stddev = 0.0;
        for (int row = 0; row < dataset->rowCount; row++) {
            mean += dataset->data[row][col];
        }
        mean /= dataset->rowCount;
        for (int row = 0; row < dataset->rowCount; row++) {
            stddev += pow(dataset->data[row][col] - mean, 2);
        }
        stddev = sqrt(stddev / dataset->rowCount);
        for (int row = 0; row < dataset->rowCount; row++) {
            double zScore = (dataset->data[row][col] - mean) / stddev;
            if (fabs(zScore) > 3.0) {
                anomalies->entries[anomalies->count].row = row;
                anomalies->entries[anomalies->count].column = col;
                anomalies->entries[anomalies->count].value = dataset->data[row][col];
                anomalies->count++;
            }
        }
    }
    return anomalies;
}