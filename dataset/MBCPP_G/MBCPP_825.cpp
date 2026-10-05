vector<int> result;
for (int index : listIndex) {
    if (index >= 0 && index < nums.size()) {
        result.push_back(nums[index]);
    }
}
return result;
}