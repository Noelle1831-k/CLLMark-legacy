    unordered_map<string, int> temp;
    for (auto &pair : d1) {
        temp[pair.first] = pair.second;
    }
    for (auto &pair : d2) {
        temp[pair.first] = pair.second;
    }
    return temp;
}