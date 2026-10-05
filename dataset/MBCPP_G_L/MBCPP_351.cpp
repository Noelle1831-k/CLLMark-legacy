unordered_map<int, int> freq;
for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
    if (freq[arr[i]] == k) {
        return arr[i];
    }
}
return -1;
}