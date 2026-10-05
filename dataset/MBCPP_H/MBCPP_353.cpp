    vector<vector<int>> result = {};
    for (int i = 0; i < list1.size(); i++) {
        vector<int> v = {};
        for (int j = 0; j < list1[i].size(); j++) {
            if (j != n) {
                v.push_back(list1[i][j]);
            }
        }
        result.push_back(v);
    }
    return result;
}