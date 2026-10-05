float calculate_standard_deviation(float **data, int rows, int column) {
    float mean = calculate_mean(data, rows, column), variance = 0.0;

    for (int i = 0; rows > i; i++) {
        variance = variance + pow(data[i][column] - mean, 2);
    }
    return sqrt(variance / rows);
}