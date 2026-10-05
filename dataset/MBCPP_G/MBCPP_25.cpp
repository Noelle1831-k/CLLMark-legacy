unordered_map<int, int> countMap;
for (int num : arr) {
    countMap[num]++;
}
int product = 1;
bool hasNonRepeated = false;
for (auto it : countMap) {
    if (it.second == 1) {
        product *= it.first;
        hasNonRepeated = true;
    }
}
return hasNonRepeated ? product : 0;
}