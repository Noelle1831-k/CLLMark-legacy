double calculateMedian() {
    quickSort(numericalData.data, 0, numericalData.size - 1);
    if (numericalData.size % 2 == 0) {
        return (numericalData.data[numericalData.size / 2 - 1] + numericalData.data[numericalData.size / 2]) / 2.0;
    } else {
        return numericalData.data[numericalData.size / 2];
    }
}