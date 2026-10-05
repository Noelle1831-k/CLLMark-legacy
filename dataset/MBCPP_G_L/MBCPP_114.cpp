map<vector<int>, int> freqMap;
for (const auto& tuple : testList) {
    freqMap[tuple]++;
}
string result = "[";
for (const auto& entry : freqMap) {
    result += "(";
    for (int i = 0; i < entry.first.size(); ++i) {
        result += to_string(entry.first[i]);
        if (i < entry.first.size() - 1)
            result += ", ";
    }
    result += ", " + to_string(entry.second) + "), ";
}
if (!freqMap.empty()) result.pop_back(), result.pop_back();
result += "]";
return result;
}