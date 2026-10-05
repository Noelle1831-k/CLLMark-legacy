vector<int> nums;
for(const auto& str : numsStr) {
    nums.push_back(stoi(str));
}
sort(nums.begin(), nums.end());
return nums;
}