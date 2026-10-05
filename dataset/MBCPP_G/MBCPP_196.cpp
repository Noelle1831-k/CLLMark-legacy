vector<vector<int>> result;
for(auto& tuple : testList) {
    if(tuple.size() != k) {
        result.push_back(tuple);
    }
}
return result;
}