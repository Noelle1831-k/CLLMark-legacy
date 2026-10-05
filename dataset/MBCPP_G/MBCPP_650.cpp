if (n != m) return false;
unordered_map<int, int> countMap;
for (int num : arr1) {
    countMap[num]++;
}
for (int num : arr2) {
    if (countMap[num] == 0) return false;
    countMap[num]--;
}
for (auto it : countMap) {
    if (it.second != 0) return false;
}
return true;
}