unordered_map<string, int> positionMap;
    int pos = 0;
    for (const auto& s : l2) {
        positionMap[s] = pos++;
    }
    vector<int> order;
    for (const auto& s : l1) {
        if (positionMap.find(s) != positionMap.end()) {
            order.push_back(positionMap[s]);
        }
    }
    return is_sorted(order.begin(), order.end());
}