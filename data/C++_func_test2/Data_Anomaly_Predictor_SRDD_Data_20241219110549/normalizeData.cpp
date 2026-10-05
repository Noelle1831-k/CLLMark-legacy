void DataLoader::normalizeData() {
    size_t i, j;
    for (i = 0; i < data[0].size(); i++) {
        double minVal = data[0][i];
        double maxVal = data[0][i];
        for (j = 0; j < data.size(); j++) {
            minVal = min(minVal, data[j][i]);
            maxVal = max(maxVal, data[j][i]);
        }
        for (j = 0; j < data.size(); j++) {
            data[j][i] = (data[j][i] - minVal) / (maxVal - minVal);
        }
    }
}