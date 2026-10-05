unordered_map<int, int> freq;
int count = 0;
for (int i = 0; i < n; i++) {
    int complement = sum - arr[i];
    if (freq.find(complement) != freq.end()) {
        count += freq[complement];
    }
    freq[arr[i]]++;
}
return count;
}