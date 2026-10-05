bool checkValid(bool testTup[], int size) {
    for (int i = 0; i < size; i++) {
        if (!testTup[i]) {
            return false;
        }
    }
    return true;
}