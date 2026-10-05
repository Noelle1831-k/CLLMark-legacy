unordered_map<string, int> result;
for (const auto& pair : dict) {
    if (pair.second >= n) {
        result.insert(pair);
    }
}
return result;
}