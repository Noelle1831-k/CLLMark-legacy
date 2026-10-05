map<int, vector<int>> grouped;
for(const auto& tup : testList) {
    grouped[tup[0]].push_back(tup[1]);
}
vector<vector<int>> result;
for(const auto& [key, values] : grouped) {
    vector<int> merged = {key};
    merged.insert(merged.end(), values.begin(), values.end());
    result.push_back(merged);
}
return result;
}