    int i;
    int result;
    for (i = 0; i < testTup1.size(); i++) {
        result = testTup1[i] - testTup2[i];
        testTup1[i] = result;
    }
    return testTup1;
}