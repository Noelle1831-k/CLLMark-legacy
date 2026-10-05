	for (int i = 0; i < nums.size(); i += 2) {
		if (nums[i] % 2 == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	vector<int> nums = {2, 1, 4, 3, 6, 7, 6, 3};
	cout << oddPosition(nums) << endl;
	return 0;
}
<|endoftext|>