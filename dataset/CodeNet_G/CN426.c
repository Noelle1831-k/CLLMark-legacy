int power_of_3(int x) {
    int result = 1;
    for (int i = 0; i < x; i++) {
        result *= 3;
    }
    return result;
}
int min_moves(int state, int n, int m) {
    int targetA = state % power_of_3(n);
    int targetC = state / power_of_3(n);
    int moves = 0;
    for (int i = 0; i < n; i++) {
        int aPos = targetA % 3;
        int cPos = targetC % 3;
        if (aPos != 0) moves++;
        if (cPos != 0) moves++;
        targetA /= 3;
        targetC /= 3;
    }
    if (moves > m) return -1;
    return moves;
}
