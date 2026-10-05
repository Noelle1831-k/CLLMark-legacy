    auto result = vector<unordered_map<string, unordered_map<string, int>>>();
    for(int i = 0; i < l1.size(); i++){
        unordered_map<string, unordered_map<string, int>> new_map = unordered_map<string, unordered_map<string, int>>();
        new_map[l1[i]] = unordered_map<string, int>();
        new_map[l1[i]][l2[i]] = l3[i];
        result.push_back(new_map);
    }
    return result;
}