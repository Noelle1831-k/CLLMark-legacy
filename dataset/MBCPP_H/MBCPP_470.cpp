    vector<int> resultTup;
    int i = 0;
    int sum = 0;
    resultTup.resize(testTup.size() - 1);
    while (i < testTup.size() - 1) {
        sum = testTup[i] + testTup[i + 1];
        resultTup[i] = sum;
        i++;
    }
    return resultTup;
}