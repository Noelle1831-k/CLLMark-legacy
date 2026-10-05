    unordered_set<string> set = {};
    for (auto i : t) {
        if (set.find(i) != set.end()) {
            set.insert(i);
        } else {
            set.insert(i);
            set.insert(i);
        }
    }
    return set;
}