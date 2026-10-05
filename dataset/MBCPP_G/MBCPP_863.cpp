unordered_set<int> elements(arr.begin(), arr.end());
int longestStreak = 0;
for (int num : arr) {
    if (!elements.count(num - 1)) {
        int currentNum = num;
        int currentStreak = 1;
        while (elements.count(currentNum + 1)) {
            currentNum += 1;
            currentStreak += 1;
        }
        longestStreak = max(longestStreak, currentStreak);
    }
}
return longestStreak;
}