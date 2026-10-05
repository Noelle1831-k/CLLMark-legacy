unordered_set<string> removeSet(removewords.begin(), removewords.end());
vector<string> result;
for (const string& word : list1) {
    if (removeSet.find(word) == removeSet.end()) {
        result.push_back(word);
    }
}
return result;
}