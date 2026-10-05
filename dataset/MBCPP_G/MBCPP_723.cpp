int count = 0;
map<int, int> freq1, freq2;
for (int num : nums1) freq1[num]++;
for (int num : nums2) freq2[num]++;
for (auto &pair : freq1) {
    int num = pair.first;
    if (freq2.find(num) != freq2.end()) {
        count += min(freq1[num], freq2[num]);
    }
}
return count;
}