int countWhiteStones(int n, int stones[]) {
    int table[100000];
    int tableSize = 0;
    for (int i = 0; i < n; ++i) {
        int currentStone = stones[i];
        if ((i + 1) % 2 != 0) {
            table[tableSize++] = currentStone;
        } else {
            if (tableSize == 0 || table[tableSize - 1] == currentStone) {
                table[tableSize++] = currentStone;
            } else {
                while (tableSize > 0 && table[tableSize - 1] != currentStone) {
                    --tableSize;
                }
                table[tableSize++] = currentStone;
            }
        }
    }
    int whiteCount = 0;
    for (int i = 0; i < tableSize; ++i) {
        if (table[i] == 0) {
            ++whiteCount;
        }
    }
    return whiteCount;
}