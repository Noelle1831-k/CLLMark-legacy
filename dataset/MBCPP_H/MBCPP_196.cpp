    vector<vector<int>> result = vector<vector<int>>();
    for (auto v : testList) {
        if (v.size() != k) {
            result.push_back(v);
        }
    }
    return result;
}