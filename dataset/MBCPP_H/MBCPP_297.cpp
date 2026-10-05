    vector<int> result = {};
    for (auto v : list1) {
        for (auto w : v) {
            result.push_back(w);
        }
    }
    return result;
}