bool checkNone(int testTup[], int size) {
    for (int i = 0; i < size; i++) {
        if (testTup[i] == -1) {
            return true;
        }
    }
    return false;
}