    vector<vector<int>> result = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    for (int i = 0; i < testTup1.size(); i++) {
        for (int j = 0; j < testTup1[i].size(); j++) {
            result[i][j] = testTup1[i][j] + testTup2[i][j];
        }
    }
    return result;
}