bool can_complete_roundtrip(int N, int distances[]) {
    int forward[N], backward[N];
    forward[0] = distances[0];
    for (int i = 1; i < N; i++) {
        forward[i] = (i * 10 <= forward[i - 1]) ? i * 10 + distances[i] : -1;
    }
    backward[N - 1] = (N - 1) * 10 - distances[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        backward[i] = ((i + 1) * 10 >= backward[i + 1]) ? (i * 10) - distances[i] : -1;
    }
    return forward[N - 1] != -1 && backward[0] <= 0;
}
