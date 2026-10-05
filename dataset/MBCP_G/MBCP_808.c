bool checkK(int* testTup, int size, int k) {
    for (int i = 0; i < size; i++) {
        if (testTup[i] == k) {
            return true;
        }
    }
    return false;
}