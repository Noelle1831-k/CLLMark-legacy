    unordered_map<int, int> map = {};
    for (auto v : nums) {
        for (auto w : v) {
            if (map.find(w) != map.end()) {
                map[w] += 1;
            } else {
                map[w] = 1;
            }
        }
    }
    return map;
}