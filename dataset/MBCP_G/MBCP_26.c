bool checkKElements(int** testList, int* sizes, int listSize, int k) {
    for (int i = 0; i < listSize; ++i) {
        for (int j = 0; j < sizes[i]; ++j) {
            if (testList[i][j] != k) {
                return false;
            }
        }
    }
    return true;
}