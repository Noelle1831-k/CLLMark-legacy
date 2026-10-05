int sampleNam(const char* sampleNames[], int size) {
    int totalLength = 0;
    for (int i = 0; i < size; i++) {
        if (!islower(sampleNames[i][0])) {
            totalLength += strlen(sampleNames[i]);
        }
    }
    return totalLength;
}
