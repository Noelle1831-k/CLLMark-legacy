int n = nums.size();
vector<int> result;
for (int i = 0; i < n - 1; ++i) {
    result.push_back(nums[i] * nums[i + 1]);
}
return result;
}