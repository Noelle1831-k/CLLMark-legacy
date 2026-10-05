double calculate_stddev(double *data, int size, double mean) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(sum / size);
}