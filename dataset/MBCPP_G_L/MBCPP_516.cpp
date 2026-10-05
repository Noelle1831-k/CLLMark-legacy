if (nums.empty()) return nums;
int max_num = *max_element(nums.begin(), nums.end());
int exp = 1;
vector<int> output(nums.size());
while (max_num / exp > 0) {
    vector<int> count(10, 0);
    for (int num : nums) {
        count[(num / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
        output[count[(nums[i] / exp) % 10] - 1] = nums[i];
        count[(nums[i] / exp) % 10]--;
    }
    nums = output;
    exp *= 10;
}
return nums;
}