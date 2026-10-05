unordered_set<int> elementsSet;
    unordered_set<int> resultSet;
    for(const auto& innerList : testList) {
        for(int num : innerList) {
            if(elementsSet.find(num) == elementsSet.end()) {
                elementsSet.insert(num);
                resultSet.insert(num);
            } else {
                resultSet.erase(num);
            }
        }
    }
    return vector<int>(resultSet.begin(), resultSet.end());
}