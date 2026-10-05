    vector<vector<int>> result;
    vector<string> tuple;
    for (auto &tuple : tupleStr) {
        vector<int> list;
        for (auto item : tuple) {
            int number = stoi(item);
            list.push_back(number);
        }
        result.push_back(list);
    }
    return result;
}