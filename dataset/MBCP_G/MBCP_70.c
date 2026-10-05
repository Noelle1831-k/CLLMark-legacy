const char* getEqual(int input[][100], int numTuples, int k) {
    for (int i = 0; i < numTuples; i++) {
        int length = 0;
        for (int j = 0; j < 100; j++) {
            if (input[i][j] != 0) {
                length++;
            } else {
                break;
            }
        }
        if (length != k) {
            return "All tuples do not have same length";
        }
    }
    return "All tuples have same length";
}