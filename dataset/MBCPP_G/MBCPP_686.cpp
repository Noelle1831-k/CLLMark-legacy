unordered_map<int, int> freqMap;
    for (int num : testTup) {
        freqMap[num]++;
    }
    string result = "{";
    for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
        if (it != freqMap.begin()) result += ", ";
        result += to_string(it->first) + ": " + to_string(it->second);
    }
    result += "}";
    return result;
}