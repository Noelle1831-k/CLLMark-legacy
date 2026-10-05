	int i, k;
	while (nums.size() > 1) {
		k = max_element(nums.begin(), nums.end()) - nums.begin();
		reverse(nums.begin(), nums.begin() + k + 1);
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k + 1);
		nums.erase(nums.begin() + k);
	}
	return nums;
}
int main() {
	vector<int> nums = {41, 42, 32, 12, 23};
	nums = pancakeSort(nums);
	cout << nums[0] << ", " << nums[1] << ", " << nums[2] << ", " << nums[3] << ", " << nums[4];
	return 0;
}
<|endoftext|>