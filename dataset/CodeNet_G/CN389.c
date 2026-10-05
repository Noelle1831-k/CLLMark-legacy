int max_height(int N, int K) {
    int stages = 0;
    while (N > 0) {
        stages++;
        int blocks_in_stage = N % (K + 1);
        if (blocks_in_stage == 0)
            blocks_in_stage = K;
        N -= blocks_in_stage;
    }
    return stages;
}