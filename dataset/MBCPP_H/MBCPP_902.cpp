    unordered_map<string, int> map = d1;
    for (auto e : d2) {
        if (map.find(e.first) != map.end()) {
            map[e.first] += e.second;
        } else {
            map[e.first] = e.second;
        }
    }
    return map;
}