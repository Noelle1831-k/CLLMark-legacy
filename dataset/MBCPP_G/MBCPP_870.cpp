return accumulate(nums.begin(), nums.end(), 0, [](int sum, int num) { return num > 0 ? sum + num : sum; });
}