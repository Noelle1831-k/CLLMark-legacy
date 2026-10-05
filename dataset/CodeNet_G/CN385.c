long long perform_rotation(int K, long long position, int card) {
    if (card > 0) {
        position = (position + card) % K;
    } else if (card < 0) {
        position = (position + K + card % K) % K;
    } else {
        position = (K - position) % K;
    }
    return position;
}
void mysterious_device(int K, int N, int Q, int *A, int *L, int *R, int *result) {
    for (int i = 0; i < Q; i++) {
        int temp = A[L[i] - 1];
        A[L[i] - 1] = A[R[i] - 1];
        A[R[i] - 1] = temp;
        long long position = 0;
        for (int j = 0; j < N; j++) {
            position = perform_rotation(K, position, A[j]);
        }
        if (position == 0) {
            result[i] = 1;
        } else {
            result[i] = position > 0 ? position + 1 : -position;
        }
    }
}
