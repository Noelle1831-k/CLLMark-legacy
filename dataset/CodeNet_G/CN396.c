int determine_winner(int N, int* whites, int* blacks) {
    int xor_sum = 0;
    for (int i = 0; i < N; i++) {
        int w = whites[i];
        int b = blacks[i];
        xor_sum ^= (b % (w + 1));
    }
    return xor_sum == 0 ? 1 : 0;
}