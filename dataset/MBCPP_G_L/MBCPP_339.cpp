if (x > y)
    return -1;
int maxDivisor = 1, maxCount = 0;
unordered_map<int, int> divisorCount;
for (int i = x; i <= y; ++i) {
    for (int j = 1; j * j <= i; ++j) {
        if (i % j == 0) {
            divisorCount[j]++;
            if (j != i / j)
                divisorCount[i / j]++;
        }
    }
}
for (auto &pair : divisorCount) {
    if (pair.second > maxCount || (pair.second == maxCount && pair.first < maxDivisor)) {
        maxCount = pair.second;
        maxDivisor = pair.first;
    }
}
return maxDivisor;
}