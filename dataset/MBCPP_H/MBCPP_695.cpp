    int len = testTup1.size();
    for (int i = 0; i < len; i++) {
        if (testTup1[i] > testTup2[i]) {
            return false;
        }
    }
    return true;
}