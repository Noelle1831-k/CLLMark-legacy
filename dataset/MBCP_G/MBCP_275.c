int getPosition(int* a, int n, int m) {
    int removedIndex = -1;
    int countRemoved = 0;
    while (countRemoved < m) {
        for (int i = 0; i < n; i++) {
            if (a[i] != -1) {
                countRemoved++;
                removedIndex = i + 1;
                a[i] = -1;
                if (countRemoved == m) {
                    break;
                }
            }
        }
    }
    return removedIndex;
}