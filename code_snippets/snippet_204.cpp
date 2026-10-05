	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] % 2 == 0)
			return nums[i];
	}
	return -1;
}
int main() {
	vector<int> nums = {2, 3, 4};
	cout << firstEven(nums) << endl; 
	nums = {5, 6, 7};
	cout << firstEven(nums) << endl; 
	return 0;
}
<|endoftext|>