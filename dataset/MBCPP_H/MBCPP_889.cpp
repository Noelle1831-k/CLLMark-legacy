    vector<vector<int>> result = vector<vector<int>>();
    for (auto v : lists) {
        vector<int> newList = vector<int>();
        for (int i = v.size() - 1; i >= 0; i--) {
            newList.push_back(v[i]);
        }
        result.push_back(newList);
    }
    return result;
}