typedef struct {
    int position;
    int direction;
} Piece;
int cmp(const void *a, const void *b) {
    Piece *p1 = (Piece *)a;
    Piece *p2 = (Piece *)b;
    return p1->position - p2->position;
}
long long calculate_max_points(Piece *pieces, int N, int L) {
    qsort(pieces, N, sizeof(Piece), cmp);
    long long max_points = 0;
    int left = 0, right = N - 1;
    while (left <= right) {
        if (pieces[left].direction == 0) {
            max_points += pieces[left].position - 1;
            left++;
        } else if (pieces[right].direction == 1) {
            max_points += L - pieces[right].position;
            right--;
        } else {
            int left_move = L - pieces[right].position;
            int right_move = pieces[left].position - 1;
            if (left_move > right_move) {
                max_points += left_move;
                right--;
            } else {
                max_points += right_move;
                left++;
            }
        }
    }
    return max_points;
}
int main(void) {
    int N, L;
    scanf("%d %d", &N, &L);
    Piece *pieces = (Piece *)malloc(N * sizeof(Piece));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &pieces[i].position, &pieces[i].direction);
    }
    printf("%lld\n", calculate_max_points(pieces, N, L));
    free(pieces);
    return 0;
}