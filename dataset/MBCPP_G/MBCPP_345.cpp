vector<int> differences;
for (int i = 0; i < nums.size() - 1; ++i) {
    differences.push_back(nums[i + 1] - nums[i]);
}
return differences;
}