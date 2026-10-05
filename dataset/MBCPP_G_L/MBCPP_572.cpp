unordered_map<int, int> freq;
for (int num : nums) {
    freq[num]++;
}
vector<int> result;
for (int num : nums) {
    if (freq[num] != 2) {
        result.push_back(num);
    }
}
return result;
}