    unordered_map<string, int> result;
    for (auto entry : dict) {
        if (entry.second >= n) {
            result[entry.first] = entry.second;
        }
    }
    return result;
}