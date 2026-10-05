set<string> seen;
vector<string> result;
for (const string& word : l) {
    if (seen.find(word) == seen.end()) {
        result.push_back(word);
        seen.insert(word);
    }
}
return result;
}