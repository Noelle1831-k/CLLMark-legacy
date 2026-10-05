float calculate_mean(float **data, int rows, int column) {
    float sum = 0.0;
    for (int i = 0; i < rows; i++) {
        sum += data[i][column];
    }
    return sum / rows;
}