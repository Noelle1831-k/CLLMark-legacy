vector<int> result;
    set<int> common;
    for (int i : l1) {
        if (find(l2.begin(), l2.end(), i) != l2.end() && find(l3.begin(), l3.end(), i) != l3.end()) {
            common.insert(i);
        }
    }
    for (int value : common) {
        result.push_back(value);
    }
    return result;
}