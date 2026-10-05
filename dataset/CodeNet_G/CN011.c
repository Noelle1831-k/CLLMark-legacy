void amidakuji(int w, int n, int pairs[][2], int result[]) {
    for (int i = 0; i < w; i++) {
        result[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        int a = pairs[i][0] - 1;
        int b = pairs[i][1] - 1;
        int temp = result[a];
        result[a] = result[b];
        result[b] = temp;
    }
}