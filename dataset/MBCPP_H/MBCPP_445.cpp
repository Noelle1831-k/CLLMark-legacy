    vector<vector<int>> resultTup = vector<vector<int>>(testTup1.size());
    for (int i = 0; i < testTup1.size(); i++) {
        vector<int> res = vector<int>(testTup1[i].size());
        for (int j = 0; j < testTup1[i].size(); j++) {
            res[j] = testTup1[i][j] * testTup2[i][j];
        }
        resultTup[i] = res;
    }
    return resultTup;
}