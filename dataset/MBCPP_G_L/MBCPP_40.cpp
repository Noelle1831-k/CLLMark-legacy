unordered_map<int, int> frequency;
for (const auto& sublist : nums) {
    for (int num : sublist) {
        frequency[num]++;
    }
}
return frequency;
}