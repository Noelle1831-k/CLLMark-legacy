void findCombinations(int testList[][2], int size, int result[][2], int *resultSize) {
    int index = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            result[index][0] = testList[i][0] + testList[j][0];
            result[index][1] = testList[i][1] + testList[j][1];
            index++;
        }
    }
    *resultSize = index;
}
