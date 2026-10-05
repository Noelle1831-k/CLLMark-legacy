unordered_map<int, int> frequencyMap;
int maxFreq = 0, maxValue = nums[0];
for (int num : nums) {
    frequencyMap[num]++;
    if (frequencyMap[num] > maxFreq) {
        maxFreq = frequencyMap[num];
        maxValue = num;
    }
}
return {maxValue, maxFreq};
}