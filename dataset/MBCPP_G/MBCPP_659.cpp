unordered_map<int, int> freq;
vector<int> result;
for (int num : x) {
    freq[num]++;
}
for (auto &entry : freq) {
    if (entry.second > 1) {
        result.push_back(entry.first);
    }
}
return result;
}