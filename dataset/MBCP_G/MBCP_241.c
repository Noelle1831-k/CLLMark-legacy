char*** create3DArray(int m, int n, int o) {
    char ***arr = (char ***)malloc(o * sizeof(char **));
    for (int i = 0; i < o; i++) {
        arr[i] = (char **)malloc(n * sizeof(char *));
        for (int j = 0; j < n; j++) {
            arr[i][j] = (char *)malloc(m * sizeof(char));
            for (int k = 0; k < m; k++) {
                arr[i][j][k] = '*';
            }
        }
    }
    return arr;
}