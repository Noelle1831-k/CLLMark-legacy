    vector<vector<int>> result = vector<vector<int>>();
    for (int i = 0; i < l1.size() - 1; i++) {
        vector<int> r = vector<int>();
        r.push_back(l1[i]);
        r.push_back(l1[i + 1]);
        result.push_back(r);
    }
    return result;
}