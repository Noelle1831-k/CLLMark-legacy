unordered_map<int, int> freq;
int sum = 0;
for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
}
for (auto& it : freq) {
    if (it.second > 1) {
        sum += it.first;
    }
}
return sum;
}