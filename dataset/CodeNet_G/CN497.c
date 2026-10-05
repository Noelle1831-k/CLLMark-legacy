#define MAX_N 5000
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int covered[MAX_N + 1][MAX_N + 1];
    memset(covered, 0, sizeof(covered));
    for (int i = 0; i < M; i++) {
        int Ai, Bi, Xi;
        scanf("%d %d %d", &Ai, &Bi, &Xi);
        for (int x = 0; x <= Xi; x++) {
            for (int y = 0; y <= x; y++) {
                covered[Ai + x][Bi + y] = 1;
            }
        }
    }
    int count = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= a; b++) {
            if (covered[a][b]) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}