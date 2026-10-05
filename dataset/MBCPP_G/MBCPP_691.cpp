unordered_map<int, vector<int>> result;
for(auto& pair : testList) {
    result[pair[1]].push_back(pair[0]);
}
return result;
}