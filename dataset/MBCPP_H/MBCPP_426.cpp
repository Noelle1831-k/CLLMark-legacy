    std::vector<int> oddnumbers;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 1) {
            oddnumbers.push_back(nums[i]);
        }
    }
    return oddnumbers;
}