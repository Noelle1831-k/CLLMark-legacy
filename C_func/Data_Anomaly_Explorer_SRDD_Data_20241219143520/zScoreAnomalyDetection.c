void zScoreAnomalyDetection(double **data, int rows, int cols, double threshold) {
    for (int j = 0; j < cols; j++) {
        double mean = 0, stdDev = 0;
        for (int i = 0; i < rows; i++) {
            mean += data[i][j];
        }
        mean /= rows;
        for (int i = 0; i < rows; i++) {
            stdDev += pow(data[i][j] - mean, 2);
        }
        stdDev = sqrt(stdDev / rows);
        printf("Column %d anomalies:\n", j);
        for (int i = 0; i < rows; i++) {
            double zScore = (data[i][j] - mean) / stdDev;
            if (fabs(zScore) > threshold) {
                printf("Row %d, Value: %f\n", i, data[i][j]);
            }
        }
    }
}