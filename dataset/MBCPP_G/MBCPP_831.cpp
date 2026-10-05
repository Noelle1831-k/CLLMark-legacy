int count = 0;
unordered_map<int, int> freq;
for (int num : arr) {
    freq[num]++;
}
for (auto it : freq) {
    if (it.second > 1) {
        count += (it.second * (it.second - 1)) / 2;
    }
}
return count;
}