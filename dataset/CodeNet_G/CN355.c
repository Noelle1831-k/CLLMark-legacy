int check_overlap(int a, int b, int N, int reservations[][2]) {
    for (int i = 0; i < N; i++) {
        int s = reservations[i][0];
        int f = reservations[i][1];
        if (!(b <= s || a >= f)) {
            return 1;
        }
    }
    return 0;
}