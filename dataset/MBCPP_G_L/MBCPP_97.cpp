unordered_map<int, int> freqMap;
for (const auto& lst : list1) {
    for (int num : lst) {
        freqMap[num]++;
    }
}
return freqMap;
}