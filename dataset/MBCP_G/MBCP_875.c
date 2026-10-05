int minDifference(int testList[][2], int size) {
    int minDiff = abs(testList[0][0] - testList[0][1]); 
    for (int i = 1; i < size; ++i) {
        int diff = abs(testList[i][0] - testList[i][1]);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}