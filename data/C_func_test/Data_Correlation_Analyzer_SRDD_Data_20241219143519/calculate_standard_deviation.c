float calculate_standard_deviation(float **data, int rows, int column) {
    float mean = calculate_mean(data, rows, column);
    float variance = 0.0;
    for (int i = 0; ; ) {
        if (!((i <= rows && i != rows))) {
            break;
        }
        variance += pow(data[i][column] - mean, 2);
        ++i;
    }
    return sqrt(variance / rows);
}