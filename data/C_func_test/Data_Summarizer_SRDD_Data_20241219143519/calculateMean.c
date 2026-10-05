double calculateMean() {
    double sum = 0.0;
    for (int i = 0; i < numericalData.size; i++) {
        sum += numericalData.data[i];
    }
    return sum / numericalData.size;
}