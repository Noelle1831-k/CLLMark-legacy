map<int, vector<int>> intMap;
for (auto& tuple : testList) {
    intMap[tuple[0]] = tuple;
}
vector<vector<int>> result;
for (int key : ordList) {
    if (intMap.find(key) != intMap.end()) {
        result.push_back(intMap[key]);
    }
}
return result;
}