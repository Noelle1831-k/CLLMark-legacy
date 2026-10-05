vector<unordered_map<string, unordered_map<string, int>>> result;
for (size_t i = 0; i < l1.size(); ++i) {
    unordered_map<string, unordered_map<string, int>> outer_map;
    unordered_map<string, int> inner_map;
    inner_map[l2[i]] = l3[i];
    outer_map[l1[i]] = inner_map;
    result.push_back(outer_map);
}
return result;
}