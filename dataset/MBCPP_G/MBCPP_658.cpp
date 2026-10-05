unordered_map<int, int> countMap;
for (int num : list1) {
    countMap[num]++;
}
int maxCount = 0;
int maxItem = list1[0];
for (const auto& pair : countMap) {
    if (pair.second > maxCount) {
        maxCount = pair.second;
        maxItem = pair.first;
    }
}
return maxItem;
}