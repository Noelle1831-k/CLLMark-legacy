    unordered_map<int, vector<int>> result = {};
    for (auto v : testList) {
        if (result.find(v[1]) != result.end()) {
            result[v[1]].push_back(v[0]);
        } else {
            result[v[1]] = vector<int>();
            result[v[1]].push_back(v[0]);
        }
    }
    return result;
}