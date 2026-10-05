void DataTransformer::removeDuplicates(vector<vector<string>>& data) {
    unordered_set<string> seen;
    auto it = data.begin();
    while (it != data.end()) {
        string rowStr = accumulate(it->begin(), it->end(), string());
        if (seen.find(rowStr) != seen.end()) {
            it = data.erase(it);
        } else {
            seen.insert(rowStr);
            ++it;
        }
    }
}