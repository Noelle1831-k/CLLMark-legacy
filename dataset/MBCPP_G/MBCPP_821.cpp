unordered_map<string, string> mergedDict = dict1;
for (const auto& pair : dict2) {
    mergedDict[pair.first] = pair.second;
}
return mergedDict;
}