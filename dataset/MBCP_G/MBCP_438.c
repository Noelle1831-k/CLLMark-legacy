int countBidirectional(int testList[][2], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if ((testList[i][0] == testList[j][1] && testList[i][1] == testList[j][0]) ||
                (testList[i][0] == testList[j][0] && testList[i][1] == testList[j][1])) {
                count++;
            }
        }
    }
    return count;
}