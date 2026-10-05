int minimum_operations(int N, int blocks[]) {
    int total_blocks = 0;
    for (int i = 0; i < N; i++) {
        total_blocks += blocks[i];
    }
    int k = 1;
    while ((k * (k + 1)) / 2 < total_blocks) {
        k++;
    }
    if ((k * (k + 1)) / 2 != total_blocks) {
        return -1;
    }
    int target[N];
    for (int i = 0; i < N; i++) {
        target[i] = 0;
    }
    int index = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < i; j++) {
            target[index++] = i;
        }
    }
    int operations = 0;
    int temp[N];
    while (operations <= 10000) {
        int completed = 1;
        for (int i = 0; i < N; i++) {
            if (blocks[i] != target[i]) {
                completed = 0;
                break;
            }
        }
        if (completed) {
            return operations;
        }
        int base_count = blocks[0];
        for (int i = 1; i < N; i++) {
            temp[i - 1] = blocks[i];
        }
        for (int i = 0; i < base_count; i++) {
            temp[N - 1 - i] = blocks[0];
        }
        for (int i = 0; i < N; i++) {
            blocks[i] = temp[i];
        }
        operations++;
    }
    return -1;
}