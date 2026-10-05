int get_color(int x, int y) {
    int layer = (x < y ? x : y) - 1;
    if (layer >= (x < y ? y : x)) layer = (x < y ? y : x) - 1;
    return (layer % 3) + 1;
} 
void solve(int N, int K, int queries[][2]) {
    for (int i = 0; i < K; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int x = a < N - a + 1 ? a : N - a + 1;
        int y = b < N - b + 1 ? b : N - b + 1;
        printf("%d\n", get_color(x, y));
    }
}