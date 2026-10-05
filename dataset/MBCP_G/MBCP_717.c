double sdCalc(int* data, int size) {
    double sum = 0.0, mean, standardDeviation = 0.0;
    for(int i = 0; i < size; i++) {
        sum += data[i];
    }
    mean = sum / size;
    for(int i = 0; i < size; i++) {
        standardDeviation += pow(data[i] - mean, 2);
    }
    return sqrt(standardDeviation / size);
}