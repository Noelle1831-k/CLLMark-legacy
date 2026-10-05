double compute_pearson(double dataset[][MAX_VARIABLES], int rows, int col1, int col2) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, sum_y2 = 0;
    for (int i = 0; i < rows; i++) {
        double x = dataset[i][col1];
        double y = dataset[i][col2];
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
        sum_y2 += y * y;
    }
    double numerator = (rows * sum_xy) - (sum_x * sum_y);
    double denominator = sqrt((rows * sum_x2 - sum_x * sum_x) * (rows * sum_y2 - sum_y * sum_y));
    return denominator != 0 ? numerator / denominator : 0;
}