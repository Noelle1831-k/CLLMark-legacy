void tupleIntStr(char ***tupleStr, int tupleCount, int *strCount, int **result) {
    for (int i = 0; i < tupleCount; ++i) {
        for (int j = 0; j < strCount[i]; ++j) {
            result[i][j] = atoi(tupleStr[i][j]);
        }
    }
}