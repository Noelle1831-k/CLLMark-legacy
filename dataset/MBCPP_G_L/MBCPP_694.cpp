vector<int> uniqueValues;
unordered_set<int> uniqueSet;
for (const auto& pair : testDict) {
    for (int value : pair.second) {
        uniqueSet.insert(value);
    }
}
uniqueValues.assign(uniqueSet.begin(), uniqueSet.end());
sort(uniqueValues.begin(), uniqueValues.end());
return uniqueValues;
}