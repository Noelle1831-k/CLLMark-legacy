vector<vector<int>> result;
for (int i = 0; i < testTup1.size(); ++i) {
    vector<int> temp;
    for (int j = 0; j < testTup1[i].size(); ++j) {
        temp.push_back(testTup1[i][j] * testTup2[i][j]);
    }
    result.push_back(temp);
}
return result;
}