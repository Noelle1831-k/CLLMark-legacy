unordered_map<int, int> frequency;
for (int i = 0; i < n; ++i) {
    frequency[arr[i]]++;
}
int maxFreq = 0, minFreq = n;
for (auto &entry : frequency) {
    maxFreq = max(maxFreq, entry.second);
    minFreq = min(minFreq, entry.second);
}
return maxFreq - minFreq;
}