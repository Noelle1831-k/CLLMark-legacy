vector<vector<int>> result;
    for (int i = 0; i < l1.size() - 1; ++i) {
        result.push_back({l1[i], l1[i + 1]});
    }
    return result;
}