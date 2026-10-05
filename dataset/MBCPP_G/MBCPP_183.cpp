sort(arr.begin(), arr.end());
unordered_set<int> seen, pairs;
for (int num : arr) {
    if (seen.count(num - k)) pairs.insert(num - k);
    if (seen.count(num + k)) pairs.insert(num);
    seen.insert(num);
}
return pairs.size();
}