void repeatTuples(int *tuple, int tupleSize, int n, int result[][2]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tupleSize; j++) {
            result[i][j] = tuple[j];
        }
    }
}