    unordered_map<string, string> map = {};
    for (auto [key, value] : dict1) {
        map[key] = value;
    }
    for (auto [key, value] : dict2) {
        map[key] = value;
    }
    return map;
}