	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < 0) count++;
	}
	return count / (double)nums.size();
}
int main() {
	vector<int> nums = {2, 4, -6, -9, 11, -12, 14, -5, 17};
	cout << negativeCount(nums) << endl;
	return 0;
}
<|endoftext|>