int maxDifference(int testList[][2], int size) {
    int max_diff = 0;
    for (int i = 0; i < size; i++) {
        int diff = testList[i][1] - testList[i][0];
        if (diff < 0) diff = -diff;
        if (diff > max_diff) {
            max_diff = diff;
        }
    }
    return max_diff;
}