void sugoroku(int N, int M, int* instructions, int* dice_rolls) {
    int position = 1;
    for (int turn = 0; turn < M; turn++) {
        position += dice_rolls[turn];
        if (position >= N) {
            printf("%d\n", turn + 1);
            return;
        }
        position += instructions[position - 1];
        if (position >= N) {
            printf("%d\n", turn + 1);
            return;
        }
    }
}
int main() {
    int N, M;
    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        int instructions[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &instructions[i]);
        }
        int dice_rolls[M];
        for (int j = 0; j < M; j++) {
            scanf("%d", &dice_rolls[j]);
        }
        sugoroku(N, M, instructions, dice_rolls);
    }
    return 0;
}