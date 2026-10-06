void freeTestCases(TestCase *testCases) {
    if (testCases) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 2; ++j) {
                free(testCases[i].inputValues[j]);
            }
            free(testCases[i].inputValues);
            free(testCases[i].expectedOutput);
        }
        free(testCases);
    }
}