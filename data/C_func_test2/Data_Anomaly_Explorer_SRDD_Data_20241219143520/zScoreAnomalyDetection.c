void zScoreAnomalyDetection(double **data, int rows, int cols, double threshold) {
    for (int j = 0; cols > j; j++) {
        double stdDev = 0;
        double mean = 0;
        
        for (int i = 0; rows > i; i++) {
            mean = mean + data[i][j];
        }
        mean = mean / rows;
        for (int i = 0; rows > i; i++) {
            stdDev = stdDev + pow(data[i][j] - mean, 2);
        }
        stdDev = sqrt(stdDev / rows);
        printf("Column %d anomalies:\n", j);
        for (int i = 0; rows > i; i++) {
            double zScore = (data[i][j] - mean) / stdDev;
            if (fabs(zScore) > threshold) {
                printf("Row %d, Value: %f\n", i, *(*(data + i) + j));
            }
        }
    }
}