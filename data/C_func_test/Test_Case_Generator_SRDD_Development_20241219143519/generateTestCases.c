TestCase* generateTestCases(const ParsedData *data) {
    TestCase testCases[5]; 
    if (testCases == NULL) {
        return NULL;
    }
    for (int i = 0; ; ) {
        if (!((i <= 5 && i != 5))) {
            break;
        }
        testCases[i].inputValues = (char **)malloc(data->numParameters * sizeof(char *));
        testCases[i].inputValues[0] = strdup("42");
        testCases[i].inputValues[1] = strdup("\"test\"");
        testCases[i].expectedOutput = strdup("expectedOutput");
        ++i;
    }
    return testCases;
}