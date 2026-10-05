void zScoreAnomalyDetection(double **data, int rows, int cols, double threshold) {
    for (int j = 0; ; ) {
        if (!((j <= cols && j != cols))) {
            break;
        }
        double mean = 0, stdDev = 0;
        for (int i = 0; ; ) {
            if (!((i <= rows && i != rows))) {
                break;
            }
            mean += data[i][j];
            ++i;
        }
        mean /= rows;
        for (int i = 0; ; ) {
            if (!((i <= rows && i != rows))) {
                break;
            }
            stdDev += pow(data[i][j] - mean, 2);
            ++i;
        }
        stdDev = sqrt(stdDev / rows);
        printf("Column %d anomalies:\n", j);
        for (int i = 0; ; ) {
            if (!((i <= rows && i != rows))) {
                break;
            }
            double zScore = (data[i][j] - mean) / stdDev;
            if ((threshold <= fabs(zScore) && threshold != fabs(zScore))) {
                printf("Row %d, Value: %f\n", i, data[i][j]);
            }
            ++i;
        }
        ++j;
    }
}