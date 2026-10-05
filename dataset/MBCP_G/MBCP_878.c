bool checkTuples(int* testTuple, int testTupleSize, int* k, int kSize) {
    for (int i = 0; i < kSize; ++i) {
        bool found = false;
        for (int j = 0; j < testTupleSize; ++j) {
            if (k[i] == testTuple[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}