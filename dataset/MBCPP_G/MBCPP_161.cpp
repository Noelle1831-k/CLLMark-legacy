unordered_set<int> set2(list2.begin(), list2.end());
    vector<int> result;
    for (int num : list1) {
        if (set2.find(num) == set2.end()) {
            result.push_back(num);
        }
    }
    return result;
}