void perfectSquares(int a, int b, int *result, int *resultSize) {
    int start = ceil(sqrt(a));
    int end = floor(sqrt(b));
    int index = 0;
    for (int i = start; i <= end; i++) {
        result[index++] = i * i;
    }
    *resultSize = index;
}