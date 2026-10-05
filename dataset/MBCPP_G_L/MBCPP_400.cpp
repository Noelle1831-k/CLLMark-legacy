set<vector<int>> uniqueTuples;
for(auto &pair : testList) {
    sort(pair.begin(), pair.end());
    uniqueTuples.insert(pair);
}
return uniqueTuples.size();
}