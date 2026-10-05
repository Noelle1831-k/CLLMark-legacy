map<string, vector<string>> groups;
for (const auto& tuple : input) {
    groups[tuple[0]].push_back(tuple[1]);
}
vector<vector<string>> result;
for (auto& group : groups) {
    vector<string> mergedGroup;
    mergedGroup.push_back(group.first);
    mergedGroup.insert(mergedGroup.end(), group.second.begin(), group.second.end());
    result.push_back(mergedGroup);
}
return result;
}