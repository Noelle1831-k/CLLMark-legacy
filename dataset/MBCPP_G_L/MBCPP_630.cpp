vector<vector<int>> result;
for (int i = testTup[0] - 1; i <= testTup[0] + 1; ++i) {
    for (int j = testTup[1] - 1; j <= testTup[1] + 1; ++j) {
        result.push_back({i, j});
    }
}
return result;
}