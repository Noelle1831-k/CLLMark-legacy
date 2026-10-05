if (nestedlist.empty()) return {};
    unordered_set<int> common_elements(nestedlist[0].begin(), nestedlist[0].end());
    for (int i = 1; i < nestedlist.size(); ++i) {
        unordered_set<int> current_set(nestedlist[i].begin(), nestedlist[i].end());
        unordered_set<int> temp;
        for (int num : common_elements) {
            if (current_set.find(num) != current_set.end()) {
                temp.insert(num);
            }
        }
        common_elements = temp;
    }
    return vector<int>(common_elements.begin(), common_elements.end());
}