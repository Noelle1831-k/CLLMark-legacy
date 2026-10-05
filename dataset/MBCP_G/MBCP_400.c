int extractFreq(int testList[][2], int size) {
    int i, j, k, freq = 0;
    int isUnique;
    for (i = 0; i < size; i++) {
        isUnique = 1;
        for (j = 0; j < i; j++) {
            if ((testList[i][0] == testList[j][0] && testList[i][1] == testList[j][1]) ||
                (testList[i][0] == testList[j][1] && testList[i][1] == testList[j][0])) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            freq++;
        }
    }
    return freq;
}