vector<vector<int>> result;
for (const auto& vec : tupleStr) {
    vector<int> intVec;
    for (const string& str : vec) {
        intVec.push_back(stoi(str));
    }
    result.push_back(intVec);
}
return result;
}