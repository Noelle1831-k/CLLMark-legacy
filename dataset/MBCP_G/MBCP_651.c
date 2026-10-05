int checkSubset(int *testTup1, int size1, int *testTup2, int size2) {
    for (int i = 0; i < size2; i++) {
        int found = 0;
        for (int j = 0; j < size1; j++) {
            if (testTup2[i] == testTup1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0; 
        }
    }
    return 1; 
}