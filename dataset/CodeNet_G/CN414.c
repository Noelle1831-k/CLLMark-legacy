long long calculate_length(int L, int N, char snake[]) {
    long long current_length = L;
    int pair_count = 0;
    for (int i = 0; i < L - 1; i++) {
        if (snake[i] == 'o' && snake[i + 1] == 'o') {
            pair_count++;
        }
    }
    for (int i = 0; i < N; i++) {
        current_length += pair_count * 3;
        pair_count *= 2;
    }
    return current_length;
}