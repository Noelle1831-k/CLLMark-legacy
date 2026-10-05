double calculateMode() {
    int maxCount = 0, mode = numericalData.data[0], count;
    for (int i = 0; i < numericalData.size; i++) {
        count = 1;
        for (int j = i + 1; j < numericalData.size; j++) {
            if (numericalData.data[i] == numericalData.data[j]) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = numericalData.data[i];
        }
    }
    return mode;
}