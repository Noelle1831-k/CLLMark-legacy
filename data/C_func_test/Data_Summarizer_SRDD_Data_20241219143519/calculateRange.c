double calculateRange() {
    return findMax(numericalData.data, numericalData.size) - findMin(numericalData.data, numericalData.size);
}